package tp.tp1.game.characters;

import tp.tp1.game.Move;

public class DestroyerAlien {
	public final static int PUNTOS_DESTROYER = 10;
	public final static int VIDA_DESTROYER = 1;
	
	private int fil;
	private int col;
	private int puntos;
	private int resistencia;
	private boolean disparo;
	
	public DestroyerAlien(int fila, int columna) {
		this.setPuntos(PUNTOS_DESTROYER);
		this.setResistencia(VIDA_DESTROYER);
		this.setCol(columna);
		this.setFil(fila);
		this.setDisparo(false);
	}
	
	public void movimiento(Move move) {
		if(move.equals(Move.RIGHT)) {
			this.setCol(this.getCol() + 1);
		}
		else if(move.equals(Move.DOWN)) {
			this.setFil(this.getFil() + 1);
		}
		else if(move.equals(Move.LEFT)) {
			this.setCol(this.getCol() - 1);
		}
	}
	
	public void disparo() {
		
	}
	public String toString() {
		return "D["+this.getResistencia()+"]";
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

	public int getResistencia() {
		return resistencia;
	}

	public void setResistencia(int resistencia) {
		this.resistencia = resistencia;
	}

	public boolean getDisparo() {
		return disparo;
	}

	public void setDisparo(boolean disparo) {
		this.disparo = disparo;
	}

	public int getPuntos() {
		return puntos;
	}

	public void setPuntos(int puntos) {
		this.puntos = puntos;
	}
}
