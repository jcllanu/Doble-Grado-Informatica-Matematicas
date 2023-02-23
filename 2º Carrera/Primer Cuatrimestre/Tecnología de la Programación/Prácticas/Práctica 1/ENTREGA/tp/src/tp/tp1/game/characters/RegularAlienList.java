package tp.tp1.game.characters;

import tp.tp1.Level;
import tp.tp1.game.Game;
import tp.tp1.game.Move;

public class RegularAlienList {
	
	public static final int MAX_REGULAR=8;
	private int contador;
	private RegularAlien[] listaRegularAlien;
	
	public RegularAlienList( Level level) {
		this.setContador(level.getRegular());
		this.listaRegularAlien = new RegularAlien[MAX_REGULAR];
		for(int i=0; i<this.contador; i++) {
			listaRegularAlien[i]=new RegularAlien(1+i/4,3+i%4);
		}
	}

	public int getContador() {
		return contador;
	}

	public void setContador(int contador) {
		this.contador = contador;
	}

	public RegularAlien getListaRegularAlien(int i) {
		return listaRegularAlien[i];
	}

	public void setListaRegularAlien(RegularAlien regularAlien, int i) {
		this.listaRegularAlien[i] = regularAlien;
	}

	public String characterAtToString(int i, int j) {//Devuelve el string del regular en la posición i,j o el caracter vacío si no hay regular
		int cont=0;
		String devuelve="";
		boolean encontrado=false;
		
		while(!encontrado && cont<this.getContador()) {
			if(this.listaRegularAlien[cont].getFil()==i && 
				this.listaRegularAlien[cont].getCol()==j) {
				devuelve=this.listaRegularAlien[cont].toString();
				encontrado = true;
			}	
			cont ++;
		}
		return devuelve;
	}

	public int impactaLaser(UCMShipLaser laser) { //Gestiona los impactos entre laser y regulars
		int puntos=-1;
		for(int i=this.getContador()-1; i>=0; i--) {
			if(laser.getCol()==this.getListaRegularAlien(i).getCol() && laser.getFil()==this.getListaRegularAlien(i).getFil()) {
				this.getListaRegularAlien(i).setResistencia(this.getListaRegularAlien(i).getResistencia()-laser.DANNO_LASER);
				puntos=0;
				if(this.getListaRegularAlien(i).getResistencia()<=0) {
					puntos+=this.getListaRegularAlien(i).getPuntos();
					this.eliminar(i);
					
				}
				
			}
		}
		
		return puntos;
	}
	
	private void eliminar(int i)	{ //Elimina el regular i de la lista de regulars
		for(int j=i+1; j<this.getContador(); j++) {
			this.setListaRegularAlien(this.getListaRegularAlien(j),j-1);
		}
		this.setContador(this.getContador()-1);
	}

	public int shockWave() { //Quita un punto de resistencia a todos los regulars y los elimina en caso necesario
		int contReg=this.getContador(), puntos=0;
		for(int i=0; i<contReg;i++) {
			this.getListaRegularAlien(i).setResistencia(this.getListaRegularAlien(i).getResistencia()-1);
			
		}
		for(int i=contReg-1; i>=0;i--) {
			if(this.getListaRegularAlien(i).getResistencia()<=0) {
				puntos+=this.getListaRegularAlien(i).getPuntos();
				this.eliminar(i);
				
			}
		}
		return puntos;
	}

	public boolean llegaAbajo() {
		int cont=0;
		boolean end=false;
		
		while(!end && cont < this.getContador()) {
			if(this.getListaRegularAlien(cont).getFil() == Game.NUM_FILAS-1) {
				end = true;
			}
			cont++;
		}
		return end;
	}

	public int maximaColumna() {
		int maximo=0;
		
		if(this.getContador() > 0) {
			maximo = this.getListaRegularAlien(0).getCol();
		}
		for(int i=0; i<this.getContador(); i++) {
			if(this.getListaRegularAlien(i).getCol() > maximo) {
				maximo = this.getListaRegularAlien(i).getCol();
			}
		}
		return maximo;
	}

	public int minimaColumna() {
		int minimo=Game.NUM_COLUMNAS-1;
		
		if(this.getContador() > 0) {
			minimo = this.getListaRegularAlien(0).getCol();
		}
		for(int i=0; i<this.getContador(); i++) {
			
			if(this.getListaRegularAlien(i).getCol() < minimo) {
				minimo = this.getListaRegularAlien(i).getCol();
			}
		}
		return minimo;
	}

	public void movimiento(Move direccion) {
		for(int i=0; i<this.getContador(); i++) {
			this.getListaRegularAlien(i).movimiento(direccion);
		}
	}
}
