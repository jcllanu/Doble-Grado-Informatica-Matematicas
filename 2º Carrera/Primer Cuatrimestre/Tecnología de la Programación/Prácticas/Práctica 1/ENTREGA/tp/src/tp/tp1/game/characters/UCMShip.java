package tp.tp1.game.characters;

import tp.tp1.game.Game;
import tp.tp1.game.Move;

public class UCMShip {

	public final static int VIDA_UCM = 3;
	public final static int COL_INI_UCM = 4;
	
	private int resistencia;
	private int fil;
	private int col;
	private boolean disparo;
	
	public UCMShip () {
		this.setResistencia(VIDA_UCM);
		this.setCol(COL_INI_UCM);
		this.fil = Game.NUM_FILAS-1;
		this.setDisparo(false);
	}
	
	
	private void movDerecha(int celdas) {
		this.setCol(this.getCol() + celdas);
	}
	private void movIzquierda(int celdas) {
		this.setCol(this.getCol() - celdas);
	}

	public void movimiento(Move move, int celdas) {
		if(move.equals(Move.RIGHT)) {
			this.movDerecha(celdas);
		}
		else if(move.equals(Move.LEFT)) {
			this.movIzquierda(celdas);
		}
	}
	public String toString() {
		String devuelve;
		if(resistencia>0) {
			devuelve="^__^";
		}else {
			devuelve="!xx!";
		}
		return devuelve;
	}

	public int getCol() {
		return col;
	}

	public void setCol(int col) {
		this.col = col;
	}

	public int getFil() {
		return fil;
	}


	public boolean getDisparo() {
		return disparo;
	}


	public void setDisparo(boolean disparo) {
		this.disparo = disparo;
	}


	public int getResistencia() {
		return resistencia;
	}


	public void setResistencia(int resistencia) {
		this.resistencia = resistencia;
	}
}
