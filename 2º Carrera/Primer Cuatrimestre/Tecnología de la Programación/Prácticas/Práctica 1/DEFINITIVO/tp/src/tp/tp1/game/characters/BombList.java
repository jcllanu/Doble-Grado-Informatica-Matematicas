package tp.tp1.game.characters;

import tp.tp1.game.Game;

public class BombList {
	
	public final static int MAX_BOMBAS= 4;
	
	private int contador;
	private Bomb[] listaBomb;
	
	public BombList() {
		this.setContador(0);
		this.listaBomb = new Bomb[MAX_BOMBAS];
		
	}

	public int getContador() {
		return contador;
	}

	public void setContador(int contador) {
		this.contador = contador;
	}

	public Bomb getListaBomb(int i) {
		return listaBomb[i];
	}

	public void setListaBomb(Bomb bomb,int i) {
		this.listaBomb[i] = bomb;
	}

	public String characterAtToString(int i, int j) {
		boolean encontrado=false;
		int cont=0;
		String devuelve="";
		
		while(!encontrado && cont<this.getContador()) {
			if(this.listaBomb[cont].getFil()==i && 
				this.listaBomb[cont].getCol()==j) {
				devuelve=this.listaBomb[cont].toString();
				encontrado = true;
			}
			cont ++;
		}
		return devuelve;
	}

	public boolean impactaLaser(UCMShipLaser laser) {
		boolean impacto = false;
		int cont=this.getContador();
		
		for(int i=0; i<cont; i++) {
			if(laser.getCol()==this.getListaBomb(i).getCol() && laser.getFil()==this.getListaBomb(i).getFil()) {
				impacto=true;
				
				this.eliminar(i);
				
			}
		}
		
		return impacto;
	}
	
	private void eliminar(int i) {
		if(this.getListaBomb(i).getPadre()!=null) {
			this.getListaBomb(i).getPadre().setDisparo(false);
		}
		for(int j=i+1; j<this.getContador(); j++) {
			this.setListaBomb(this.getListaBomb(j),j-1);
		}
		this.setContador(this.getContador()-1);
	}

	public void movimiento() {
		for(int i=0; i<this.getContador(); i++) {
			this.getListaBomb(i).movimiento();
		}
		
	}

	public boolean impactaNave(UCMShip nave) {
		boolean impacta = false;
		for(int i=this.getContador()-1; i>=0; i--) {
			if(nave.getCol()==this.getListaBomb(i).getCol() && nave.getFil()==this.getListaBomb(i).getFil()) {
				impacta=true;
				this.eliminar(i);
				
			}
		}
		return impacta;
	}

	public void comprobarMargenes() {
		int cont=this.getContador();
		for(int i=cont-1; i>=0; i--) {/*LO HE CAMBIADO*/
			if(this.getListaBomb(i).getFil()>=Game.NUM_FILAS) {
				this.eliminar(i);
			}
		}
	}
	
	
}
