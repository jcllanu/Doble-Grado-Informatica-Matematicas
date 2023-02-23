package tp.tp1.game.characters;

import java.util.Random;

import tp.tp1.*;
import tp.tp1.game.Game;
import tp.tp1.game.Move;

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
	
	private void eliminar(int i) {
		for(int j=i+1; j<this.getContador(); j++) {
			this.setListaDestroyerAlien(this.getListaDestroyerAlien(j),j-1);
		}
		this.setContador(this.getContador()-1);
	}
	public int shockWave() {
		int contDes = this.getContador(), puntos = 0;
		for(int i=0; i<contDes;i++) {
			this.getListaDestroyerAlien(i).setResistencia(this.getListaDestroyerAlien(i).getResistencia()-1);
		}
		for(int i=contDes-1; i>=0;i--) {
			if(this.getListaDestroyerAlien(i).getResistencia()<=0) {
				puntos+=this.getListaDestroyerAlien(i).getPuntos();
				this.eliminar(i);
				
			}
		}
		return puntos;
	}

	public void dispara(Random rand, Level level, BombList listaBombas, BombList recienDisparadas) {
		int aleatorio;
		for(int i=0; i < this.getContador(); i++) {
			aleatorio=rand.nextInt(10);
			if(!this.getListaDestroyerAlien(i).getDisparo() && 
					aleatorio < level.getFrecuenciaDisp()*10) {

				this.getListaDestroyerAlien(i).setDisparo(true);
				listaBombas.setListaBomb(new Bomb(this.getListaDestroyerAlien(i)),listaBombas.getContador());
				listaBombas.setContador(listaBombas.getContador()+1);
				recienDisparadas.setListaBomb(listaBombas.getListaBomb(listaBombas.getContador()-1),recienDisparadas.getContador());
				recienDisparadas.setContador(recienDisparadas.getContador()+1);
			}
		}
		
	}

	public boolean llegaAbajo() {
		int cont=0;
		boolean end=false;
		
		while(!end && cont < this.getContador()) {
			if(this.getListaDestroyerAlien(cont).getFil() == Game.NUM_FILAS-1) {
				end = true;
			}
			cont++;
		}
		return end;
	}
	
	public int maximaColumna() {
		int maximo=0;
		
		if(this.getContador() > 0) {
			maximo = this.getListaDestroyerAlien(0).getCol();
		}
		for(int i=0; i<this.getContador(); i++) {
			if(this.getListaDestroyerAlien(i).getCol() > maximo) {
				maximo = this.getListaDestroyerAlien(i).getCol();
			}
		}
		return maximo;
	}

	public int minimaColumna() {
		int minimo=Game.NUM_COLUMNAS-1;
		
		if(this.getContador() > 0) {
			minimo = this.getListaDestroyerAlien(0).getCol();
		}
		for(int i=0; i<this.getContador(); i++) {
			
			if(this.getListaDestroyerAlien(i).getCol() < minimo) {
				minimo = this.getListaDestroyerAlien(i).getCol();
			}
		}
		return minimo;
	}
	public void movimiento(Move direccion) {
		for(int i=0; i<this.getContador(); i++) {
			this.getListaDestroyerAlien(i).movimiento(direccion);
		}
	}
}
