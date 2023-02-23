package tp.tp1.game.characters;
import tp.tp1.game.*;

public class RegularAlien {
	public final static int PUNTOS_REGULAR = 5;
	public final static int VIDA_REGULAR = 2;
	
	private int fil;
	private int col;
	private int resistencia;
	private int puntos;
	
	
	public RegularAlien(int fila, int columna) {
		this.setPuntos(PUNTOS_REGULAR) ;
		this.resistencia = VIDA_REGULAR ;
		this.setCol(columna);
		this.setFil(fila);
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
	public String toString() {
		return "C["+this.resistencia+"]";
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

	public void setResistencia(int i) {
		this.resistencia=i;
		
	}

	public int getResistencia() {
		
		return this.resistencia;
	}

	public int getPuntos() {
		return puntos;
	}

	public void setPuntos(int puntos) {
		this.puntos = puntos;
	}
}
