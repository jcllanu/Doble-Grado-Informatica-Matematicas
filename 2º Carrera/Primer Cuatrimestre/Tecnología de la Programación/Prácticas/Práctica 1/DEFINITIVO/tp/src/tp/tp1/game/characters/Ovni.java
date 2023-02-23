package tp.tp1.game.characters;

import tp.tp1.game.Game;
import tp.tp1.game.Move;

public class Ovni {
	public final static int PUNTOS_OVNI = 25;
	public final static int VIDA_OVNI = 1;
	
	private int fil;
	private int col;
	private int puntos;
	private int resistencia;
	
	public Ovni() {
		this.setPuntos(PUNTOS_OVNI);
		this.resistencia = VIDA_OVNI;
		this.setCol(Game.NUM_COLUMNAS);
		this.setFil(0);
	}
	
	public void movimiento() {
		this.setCol(this.getCol() - 1);
	}
	public String toString() {
		return "O["+this.resistencia+"]";
	}

	public int getFil() {
		return fil;
	}

	public void setFil(int fil) {
		this.fil = fil;
	}

	public int getCol() {
		return col;
	}

	public void setCol(int col) {
		this.col = col;
	}

	public int getPuntos() {
		return puntos;
	}

	public void setPuntos(int puntos) {
		this.puntos = puntos;
	}

	
}
