package tp.tp1.game.characters;

import tp.tp1.game.*;

public class UCMShipLaser {
	
	public final static int DANNO_LASER = 1;
	private int fil;
	private int col;
	private int dano;
	
	public UCMShipLaser (int columna) {
		this.col = columna;
		this.fil=Game.NUM_FILAS-1;
		this.dano = DANNO_LASER;
	}
	public void movimiento() {
		this.setFil(getFil()-1);
	}
	
	
	public void setFil(int i) {
		this.fil = i;
		
	}
	public String toString() {
		return "oo";
	}
	public int getFil() {
		return fil;
	}
	public int getCol() {
		return col;
	}
}
