package tp.tp1.game.gameObjects;

import tp.tp1.exceptions.FileContentsException;
import tp.tp1.game.FileContentsVerifier;
import tp.tp1.game.Game;

public abstract class GameObject implements IAttack{
	private int fila;
	protected int columna;
	protected int vidas;
	private Game game;
	public static final String labelRefSeparator = " - ";
	protected int label = 0;
	
	public GameObject() {
		
	}
	public GameObject(Game game, int x, int y, int live) {
		this.setFila(x);
		this. columna = y;
		this.setGame(game);
		this.vidas = live;
	}
	
	public int getFil() {
		return getFila();
	}
	public int getCol() {
		return columna;
	}
	public void setFil(int fil) {
		this.setFila(fil);
	}
	public void setCol(int col) {
		this.columna=col;
	}
	public boolean isAlive() {
		return this.vidas > 0;
	}
	public int getVida() {
		return this.vidas;
	}
	public boolean isOnPosition(int x, int y) {
		return this.getFila() == x && this.columna == y;
	}
	public void getDamage (int damage) {
		this.vidas-=damage;
	}
	public boolean isOut() {
		return !getGame().isOnBoard(getFila(), columna);
	}
	
	public abstract void computerAction() ;
	public abstract void onDelete();
	public abstract void move();
	public abstract String toString();
	public abstract int colAlien();
	public Game getGame() {
		return game;
	}
	public void setGame(Game game) {
		this.game = game;
	}
	public abstract boolean llegue();
	
	public boolean receiveExplosiveAttack(int damage) {
		this.getDamage(damage);
		return false;
	}

	public abstract String serialize();
	protected abstract GameObject parse(String stringFromFile, Game game2, FileContentsVerifier verifier, ListaLabels listaLabel) throws FileContentsException;
	public int getLabel() {
		return label;
	}

	public boolean isOwner(int ref) {
		return label == ref;
	}
	public int getFila() {
		return fila;
	}
	public void setFila(int fila) {
		this.fila = fila;
	}

	
}
