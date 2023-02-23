package tp.tp1.game.gameObjects.lists;

import tp.tp1.game.Game;
import tp.tp1.game.Move;
import tp.tp1.game.gameObjects.AlienShip;
import tp.tp1.game.gameObjects.GameObject;
import tp.tp1.game.gameObjects.Shockwave;

public class GameObjectBoard {
	private GameObject[] objects;
	private int contador;
	private Game game;
	
	public GameObjectBoard (int width, int height, Game juego) {/*HAY QUE PREGUNTAR PARA QUE NOS DAN EL WITH Y EL LENGTH*/
													
		contador=0;
		objects= new  GameObject[0];
		game=juego;
	}
	
	public void add (GameObject object) {//Añadir un objecto al final de la lista
	 GameObject[] nuevaLista = new  GameObject[contador+1];
	 for(int i=0; i<contador; i++) {
		 nuevaLista[i]=objects[i];
	 }
	 nuevaLista[contador]=object;
	 contador++;
	 objects = nuevaLista;
	}
	public void addFront (GameObject object) {//Añadir un objecto al inicio de la lista
		 GameObject[] nuevaLista = new  GameObject[contador+1];
		 for(int i=0; i<contador; i++) {
			 nuevaLista[i+1]=objects[i];
		 }
		 nuevaLista[0]=object;
		 contador++;
		 objects = nuevaLista;
	}
	public GameObject getObjectInPosition (int x, int y) {//el que llama a esta funcion que compbruebe que sepa que te puede devolver null
		GameObject object;
		int indice=this.getIndex(x,y);
		if (indice == contador){
			object = null;
		}else {
			object = this.objects[indice];
		}
		if(this.game.getNave().isOnPosition(x, y)) {
			object=this.game.getNave();
		}
		return object;
	}
	private int getIndex(int x, int y) { //el que  llame a esta funcion que compruebe que el indice devuelto esta en el rango de indices
		int index = this.contador;
		int cont = 0;
		boolean encontrado =false;
		while(cont<this.contador && !encontrado) {
			if(this.objects[cont].isOnPosition(x, y)) {
				index = cont;
				encontrado = true;
			}
			cont++;
			}
		
		return index;
	}
	
	private void remove (GameObject object) {
		object.onDelete();
	}
	
	public void update() {
		int maximo=-1, minimo=Game.NUM_COLUMNAS,aux;
		for(int i=0; i<contador;i++) {
			aux=this.objects[i].colAlien();
			if(aux!=-1) {
				if(aux>maximo) {
					maximo=aux;
				}
				if(aux<minimo) {
					minimo=aux;
				}
			}
		}
		if(minimo == 0 && this.game.getMove() == Move.LEFT) {
			this.game.setMove(Move.DOWN);
			for(int i=0; i<contador;i++) {
				this.objects[i].move();
				for(int j=0; j<contador;j++) {
					this.checkAttacks(this.objects[j]);
				}
			}
			while(this.removeDead());
			this.game.setMove(Move.RIGHT);
			
		}else if(maximo==Game.NUM_COLUMNAS-1 && this.game.getMove() == Move.RIGHT) {
			this.game.setMove(Move.DOWN);
			for(int i=0; i<contador;i++) {
				this.objects[i].move();
				for(int j=0; j<contador;j++) {
					this.checkAttacks(this.objects[j]);
				}
			}
			while(this.removeDead());
			this.game.setMove(Move.LEFT);
			
		}else{
			for(int i=0; i<contador;i++) {
				this.objects[i].move();
				for(int j=0; j<contador;j++) {
					this.checkAttacks(this.objects[j]);
				}
			}
			while(this.removeDead());
		}
		
		for(int i=0; i<contador; i++) {
			if(this.objects[i].llegue()) {
				AlienShip.sethaveLanded(true);
			}
		}
		if(!game.getHayOvni()) {
			game.getInitializer().initializeOvni(game);
		}
		
		
	}
	private void checkAttacks(GameObject object) {
		if(object.getVida()>0) {
			for(int j=0; j<contador;j++) {
				if(object.performAttack(this.objects[j])) {
					object.getDamage(object.getVida());
					
					/*return;*//*Si lo pones atacas a un objeto como máximo (puede generar problemas)*/
					
				}
			}
		}
	}
	public void computerAction() {//Llama a todos los computer action
		for(int i=contador-1; i>=0; i--) {
			this.objects[i].computerAction();
		}
	}
	public boolean removeDead() {
		boolean algunoMuere=false;
		for(int i=contador-1; i>=0; i--) {
			if(this.objects[i].getVida()<=0 || this.objects[i].isOut()) {
				algunoMuere=true;
				remove(this.objects[i]);
				for(int j=i; j<contador-1;j++) {
					this.objects[j]=this.objects[j+1];
				}
				contador--;
			}
		}
		return algunoMuere;
	}
	public String toString(int x, int y) {
		String devuelve = "";
		GameObject object = this.getObjectInPosition(x, y);
		
		if(object!=null) {
			devuelve = object.toString();
		}
		return devuelve ;

	}

	public void shockWaveAttack() {
		Shockwave shock=new Shockwave(game, 0, 0, 0);
		for(int i=0; i<contador; i++) {
			shock.performAttack(this.objects[i]);
		}
		
	}

	public String serialize() {
		String dev="\n";
		for(int i=0; i<contador;i++) {
			dev+=this.objects[i].serialize()+"\n";
		}
		return dev;
	}
	public GameObject getLabelOwner(int ref) {
		for (int i=0; i<contador; i++) {
			if (objects[i].isOwner(ref))
				return objects[i];
		}
		return null;
	}

	

}
