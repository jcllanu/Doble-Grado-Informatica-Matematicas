/*-------------------------------------------------------------------
**
**  Fichero:
**    intcontroller.c  3/3/2016
**
**    Estructura de Computadores
**    Dpto. de Arquitectura de Computadores y Automática
**    Facultad de Informática. Universidad Complutense de Madrid
**
**  Propósito:
**    Contiene las implementación del módulo intcontroller
**
**-----------------------------------------------------------------*/

/*--- ficheros de cabecera ---*/
#include "44b.h"
#include "intcontroller.h"

void ic_init(void)
{
	/* Configuración por defecto del controlador de interrupciones:
	 *    Lineas IRQ y FIQ no habilitadas
	 *    Linea IRQ en modo no vectorizado
	 *    Todo por la línea IRQ
	 *    Todas las interrupciones enmascaradas
	 **/
	rINTMOD = 0x0; // Configura las lineas como de tipo IRQ
	rINTCON = 0x7; // IRQ y FIQ enmascaradas, IRQ en modo no vectorizado
	rINTMSK = ~(0x0); // Enmascara todas las lineas
}

int ic_conf_irq(enum enable st, enum int_vec vec)
{
	int conf = rINTCON;

	if (st != ENABLE && st != DISABLE)
		return -1;

	if (vec == VEC){
		//COMPLETAR: poner la linea IRQ en modo vectorizado
		conf = conf & ~(1<<2);//Poner el bit 2 de INTCON a 0
	}
	else{
		//COMPLETAR: poner la linea IRQ en modo no vectorizado
		conf = conf |(1<<2);//Poner el bit 2 de INTCON a 1
	}

	if (st == ENABLE){
		//COMPLETAR: habilitar la linea IRQ
		conf = conf & ~(1 << 1);//Poner el bit 1 de INTCON a 0
	}
	else{
		//COMPLETAR: deshabilitar la linea IRQ
		conf = conf | (1 << 1);//Poner el bit 1 de INTCON a 1
	}

	rINTCON = conf;

	return 0;
}

int ic_conf_fiq(enum enable st)
{
	int ret = 0;

	if (st == ENABLE){
		//COMPLETAR: habilitar la linea FIQ
		rINTCON = rINTCON & ~1;//Poner el bit 0 de INTCON a 0
	}else if (st == DISABLE){
		//COMPLETAR: deshabilitar la linea FIQ
		rINTCON = rINTCON | 1;//Poner el bit 0 de INTCON a 1
	}else
		ret = -1;

	return ret;
}

int ic_conf_line(enum int_line line, enum int_mode mode)
{
	unsigned int bit = INT_BIT(line);

	if (line < 0 || line > 26)
		return -1;

	if (mode != IRQ && mode != FIQ)
		return -1;

	if (mode == IRQ){
		//COMPLETAR: poner la linea line en modo IRQ
		rINTMOD = rINTMOD & ~bit;//Poner el bit a 0 para que active IRQ
	}
	else{
		//COMPLETAR: poner la linea line en modo FIQ
		rINTMOD = rINTMOD | bit;//Poner el bit a 1 para que active FIQ
	}
	return 0;
}

int ic_enable(enum int_line line)
{
	unsigned int bit = INT_BIT(line);
	if (line < 0 || line > 26)
		return -1;

	//COMPLETAR: habilitar las interrupciones por la linea line
	//Cuando el bit toma el valor 0 habilita la interrupci�n de la linea correspondiente
	rINTMSK = rINTMSK & ~(1<<26);//HAY QUE DESENMASCARAR TODOS LOS BITS
	rINTMSK = rINTMSK & ~bit;
	return 0;
}

int ic_disable(enum int_line line)
{
	if (line < 0 || line > 26)
		return -1;

	//COMPLETAR: enmascarar las interrupciones por la linea line
	//Cuando el bit toma el valor 1 deshabilita la interrupci�n de la linea correspondiente
	rINTMSK = rINTMSK | (0x1 << line);
	return 0;
}

int ic_cleanflag(enum int_line line)
{
	int bit;

	if (line < 0 || line > 26)
		return -1;

	bit = INT_BIT(line);

	if (rINTMOD & bit){
		//COMPLETAR: borrar el flag de interrupcion correspondiente a la linea line
		//con la linea configurada por FIQ
		//Borra el bit de la INTPND escribiendo 1 en la posicion correspondiente a la linea en F_ISPC
		rF_ISPC = rF_ISPC | bit;
	}
	else{
		//COMPLETAR: borrar el flag de interrupcion correspondiente a la linea line
		//con la linea configurada por IRQ
		//Igual que el anterior pero en vez de interrupciones FIQ ahora del tipo IRQ
		rI_ISPC = rI_ISPC | bit;
	}
	return 0;
}



