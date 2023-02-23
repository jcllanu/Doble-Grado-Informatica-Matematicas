package tp.tp1.game.characters;

import tp.tp1.Level;

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

	public String characterAtToString(int i, int j) {
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

	public int impactaLaser(UCMShipLaser laser) {
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
	
	public void eliminar(int i)	{
		for(int j=i+1; j<this.getContador(); j++) {
			this.setListaRegularAlien(this.getListaRegularAlien(j),j-1);
		}
		this.setContador(this.getContador()-1);
	}
}
