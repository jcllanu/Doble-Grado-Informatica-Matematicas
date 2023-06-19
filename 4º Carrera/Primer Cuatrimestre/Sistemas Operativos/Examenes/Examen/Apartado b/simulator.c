#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

#define N_PARADAS 5 // número de paradas de la ruta
#define EN_RUTA 0 // autobús en ruta
#define EN_PARADA 1 // autobús en la parada
#define MAX_USUARIOS 40 // capacidad del autobús
#define USUARIOS 4 // numero de usuarios
#define MAX_VIAJES 4 //numero máximo de viajes que realiza cada usuario
#define MIN_VIAJES 2 //numero mínimo de viajes que realiza cada usuario
#define MIN_VUELTAS 2 //numero mínimo de vueltas que da el autobus a la ruta circular antes de irse a dormir

//NUEVO
#define USUARIOS_NOPRIO 0
#define USUARIOS_PRIO 1

// estado inicial
int estado = EN_RUTA;
int parada_actual = 0; // parada en la que se encuentra el autobus
int n_ocupantes = 0; // ocupantes que tiene el autobús
int viajeros_con_BONOBUS = 0;
// personas que desean subir en cada parada
int esperando_parada[N_PARADAS]; //= {0,0,...0};

// personas que desean bajar en cada parada
int esperando_bajar[N_PARADAS]; //= {0,0,...0};

// Otras definiciones globales (comunicación y sincronización)


pthread_t hilos_usuarios[USUARIOS]; // hilos de cada uno de los usuarios
pthread_t hilo_autobus; // hilo del autobus
pthread_mutex_t mutex;
pthread_cond_t b_autobus; //Variable condicional para bloquear el autobus
pthread_cond_t b_montados; //Variable condicional para bloquear a los usuarios montados en el autobus
pthread_cond_t b_en_parada; // Variable condicional para bloquear a los usuarios que están esperando en una parada


void * thread_autobus(void * args) {
	int contar_paradas=0;
	printf("El autobus comienza la ruta \n");
	//El autobus termina la ruta cuando ha dado el mínimo de vueltas a la ruta y no quedan viajeros con algún viaje en su BONOBUS
	pthread_mutex_lock(&mutex);//Para viajeros_con_BONOBUS
	while (contar_paradas<MIN_VUELTAS*N_PARADAS || viajeros_con_BONOBUS > 0) {//Cambiar por 1 para que conduzca indefinidamente
		pthread_mutex_unlock(&mutex);
		// esperar a que los viajeros suban y bajen
		Autobus_En_Parada();
		// conducir hasta siguiente parada
		Conducir_Hasta_Siguiente_Parada();
		contar_paradas++;
		pthread_mutex_lock(&mutex);//Para viajeros_con_BONOBUS
	}
	pthread_mutex_unlock(&mutex);
	printf("El autobus finaliza la ruta porque ha completado el mínimo de vueltas y todos los usuarios han agotado su BONOBUS\n");
}

void * thread_usuario(void * arg) {
	int id_usuario;
	int a,b;
	int primera_vuelta = 1;
	int num_viajes = MIN_VIAJES;

	//NUEVO
	int prio;
	// obtener el id del usario
	id_usuario=((int*)arg)[0];
	prio=((int*)arg)[1];
	//printf("Soy el usuario %d y mi prioridad es %d\n",id_usuario,prio);
	
	//Cada viajero realizará un número de viajes entre MIN_VIAJES y MAX_VIAJES 
	char* prioridad;
	if (prio==USUARIOS_NOPRIO){
		prioridad="no prio";
	}else{
		prioridad="prio";
	}
	num_viajes+=(rand()%(MAX_VIAJES-MIN_VIAJES+1));
	printf("usuario %d (%s): El usuario %d tiene %d viajes en su BONOBUS\n" , id_usuario, prioridad,id_usuario, num_viajes);
	pthread_mutex_lock(&mutex);//Para viajeros_con_BONOBUS
	viajeros_con_BONOBUS++;
	pthread_mutex_unlock(&mutex);
	while (num_viajes>0) {//Cambiar por 1 para que cada usuario haga un número indetermiando de viajes

		/*
		//En el código original, cuando un viajero baja del autobus se puede "teletransportar" a otra parada
		a=rand() % N_PARADAS;
		do{
			b=rand() % N_PARADAS;
		} while(a==b);
		Usuario(id_usuario,a,b);
		*/

		//Opción sin teletransporte
		if(primera_vuelta){
			a=rand() % N_PARADAS; //La primera vez empieza en una parada aleatoria
			primera_vuelta = 0;
		}else{
			a=b;//Las siguientes veces empieza en la parada donde se bajo en el viaje anterior
		}
		do{
			b=rand() % N_PARADAS;
		} while(a==b);
		Usuario(id_usuario,prio,a,b);
		//Simulamos un tiempo de espera para que un usuario no se baje y se vuelva a subir inmediatamente en el autobus
		sleep(1);
		num_viajes--;
	}
	printf("usuario %d (%s):El usuario %d finaliza su trayecto porque no le quedan viajes en su BONOBUS\n" ,id_usuario, prioridad, id_usuario, num_viajes);
	pthread_mutex_lock(&mutex);
	viajeros_con_BONOBUS--;
	pthread_mutex_unlock(&mutex);
}

void Usuario(int id_usuario, int prio, int origen, int destino) {
	// Esperar a que el autobus esté en parada origen para subir
	Subir_Autobus(id_usuario, prio, origen);
	// Bajarme en estación destino
	Bajar_Autobus(id_usuario, prio, destino);
}

int main(int argc, char *argv[]) {
	int i;
	// Definición de variables locales a main
	// Opcional: obtener de los argumentos del programa la capacidad del
	// autobus, el numero de usuarios y el numero de paradas

	//Inicializar los mutex
	pthread_mutex_init(&mutex,NULL);

	//Inicializar las variables condicionales
	pthread_cond_init(&b_autobus,NULL); 
	pthread_cond_init(&b_en_parada,NULL);
	pthread_cond_init(&b_montados,NULL);


	pthread_create(&hilo_autobus, NULL, thread_autobus, NULL); // Crear el thread Autobus
	int array [USUARIOS][2];
	
	for (i = 0; i<USUARIOS;i++){
		array[i][0]=i;
		if(i%2==0){
			array[i][1]=USUARIOS_NOPRIO;
		}else{
			array[i][1]=USUARIOS_PRIO;
		}
		pthread_create(&hilos_usuarios[i], NULL, thread_usuario, (void*)array[i]); // Crear thread para el usuario i
	}
	
    
	// Esperar terminación de los hilos
	for(i=0; i<USUARIOS; i++)
        pthread_join(hilos_usuarios[i],NULL);
	pthread_join(hilo_autobus,NULL);
	return 0;
}

void Autobus_En_Parada(){
	/* Ajustar el estado y bloquear al autobús hasta que no haya pasajeros que
	quieran bajar y/o subir la parada actual. Después se pone en marcha */
	pthread_mutex_lock(&mutex);
	estado = EN_PARADA;
	printf("El autobus llega a la parada %d\n" , parada_actual);

	//Avisar a los usuarios de que ha llegado a la parada
	pthread_cond_broadcast(&b_en_parada);
	pthread_cond_broadcast(&b_montados);

	//Comprueba que no queda nadie por montar ni bajar
	while(esperando_bajar[parada_actual]>0 || esperando_parada[parada_actual]>0){
		pthread_cond_wait(&b_autobus,&mutex);
	}
	printf("El autobus sale de la parada %d\n" , parada_actual);
	estado = EN_RUTA;
	pthread_mutex_unlock(&mutex);
}
void Conducir_Hasta_Siguiente_Parada(){
	/* Establecer un Retardo que simule el trayecto y actualizar numero de parada */
	sleep(random() % 5);
	pthread_mutex_lock(&mutex);
	parada_actual=(parada_actual+1==N_PARADAS)? 0 : parada_actual+1;
	pthread_mutex_unlock(&mutex);
}
void Subir_Autobus(int id_usuario, int prio, int origen){
	/* El usuario indicará que quiere subir en la parada ’origen’, esperará a que
	el autobús se pare en dicha parada y subirá. El id_usuario puede utilizarse para
	proporcionar información de depuración */
	char* prioridad;
	if (prio==USUARIOS_NOPRIO){
		prioridad="no prio";
	}else{
		prioridad="prio";
	}
	printf("usuario %d (%s):El usuario %d quiere subir en la parada %d\n" ,id_usuario, prioridad, id_usuario, origen);
	pthread_mutex_lock(&mutex);
	esperando_parada[origen]++;
	//printf("El usuario %d está esperando en la parada %d\n" , id_usuario, origen);
	while(parada_actual!=origen ||estado!=EN_PARADA || n_ocupantes==MAX_USUARIOS){
		pthread_cond_wait(&b_en_parada,&mutex);
	}
	printf("usuario %d (%s):El usuario %d sube al autobus en la parada %d\n" ,id_usuario, prioridad, id_usuario, origen);
	n_ocupantes++;
	esperando_parada[origen]--;
	//Avisa al autobus de que se ha montado
	pthread_cond_broadcast(&b_autobus);//Podría ser un signal y que avise solo el último
	pthread_mutex_unlock(&mutex);

}
void Bajar_Autobus(int id_usuario, int prio, int destino){
	/* El usuario indicará que quiere bajar en la parada ’destino’, esperará a que
	el autobús se pare en dicha parada y bajará. El id_usuario puede utilizarse para
	proporcionar información de depuración */
	char* prioridad;
	if (prio==USUARIOS_NOPRIO){
		prioridad="no prio";
	}else{
		prioridad="prio";
	}
	pthread_mutex_lock(&mutex);
	printf("usuario %d (%s):El usuario %d quiere bajarse en la parada %d\n" ,id_usuario, prioridad, id_usuario, destino);
	esperando_bajar[destino]++;
	while(parada_actual!=destino || estado!=EN_PARADA){
		pthread_cond_wait(&b_montados,&mutex);
	}
	//Llega al destino
	esperando_bajar[destino]--;
	printf("usuario %d (%s):El usuario %d se baja en la parada %d\n" ,id_usuario, prioridad, id_usuario, destino);
	n_ocupantes--;
	//Avisa al autobus de que se ha bajado
	pthread_cond_broadcast(&b_autobus);//podría ser un signal y que avise solo el último
	//Avisa a sol que están esperando en una parada porque ahora hay más hueco en el autobus
	pthread_cond_broadcast(&b_en_parada);
	pthread_mutex_unlock(&mutex);
}
