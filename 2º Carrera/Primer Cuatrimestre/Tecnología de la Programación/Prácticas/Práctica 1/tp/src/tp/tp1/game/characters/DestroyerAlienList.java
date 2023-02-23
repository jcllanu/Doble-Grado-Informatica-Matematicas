package tp.tp1.game.characters;

import tp.tp1.*;

public class DestroyerAlienList {
	public static final int MAX_DESTROYERS = 4;
	
	private int contador;
	private DestroyerAlien[] listaDestroyerAlien;
	
	
	public DestroyerAlienList(Level level) {
	
		this.listaDestroyerAlien=new DestroyerAlien[MAX_DESTROYERS];
		this.setContador(level.getDestroyers());
		for(int i=0; i<this.getContador();i++) {
			listaDestroyerAlien[i]=new DestroyerAlien(level.filDestroyer(),level.colFirstDestroyer()+i);
		}
	}

	public int getContador() {
		return contador;
	}

	public void setContador(int contador) {
		this.contador = contador;
	}

	public DestroyerAlien getListaDestroyerAlien(int i) {
		return listaDestroyerAlien[i];
	}

	public void setListaDestroyerAlien(DestroyerAlien destroyerAlien, int i) {
		this.listaDestroyerAlien[i] = destroyerAlien;
	}

	public String characterAtToString(int i, int j) {
		boolean encontrado=false;
		int cont=0;
		String devuelve="";
	
		while(!encontrado && cont<this.getContador()) {
			if(this.listaDestroyerAlien[cont].getFil()==i && 
				this.listaDestroyerAlien[cont].getCol()==j) {
				devuelve=this.listaDestroyerAlien[cont].toString();
				encontrado = true;
			}
			cont ++;
		}
		return devuelve;
	}

	public int impactaLaser(UCMShipLaser laser) {
		int puntos=-1;
		for(int i=this.getContador()-1; i>=0; i--) {
			if(laser.getCol()==this.getListaDestroyerAlien(i).getCol() && laser.getFil()==this.getListaDestroyerAlien(i).getFil()) {
				puntos=0;
				this.getListaDestroyerAlien(i).setResistencia(this.getListaDestroyerAlien(i).getResistencia()-laser.DANNO_LASER);
				if(this.getListaDestroyerAlien(i).getResistencia()<=0) {
					puntos+=this.getListaDestroyerAlien(i).getPuntos();
					this.eliminar(i);
				}
				
			}
		}
		return puntos;
	}
	
	public void eliminar(int i) {
		for(int j=i+1; j<this.getContador(); j++) {
			this.setListaDestroyerAlien(this.getListaDestroyerAlien(j),j-1);
		}
		this.setContador(this.getContador()-1);
	}
}
