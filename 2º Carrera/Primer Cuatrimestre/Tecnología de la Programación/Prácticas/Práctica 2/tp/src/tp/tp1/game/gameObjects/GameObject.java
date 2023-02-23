package tp.tp1.game.gameObjects;

import tp.tp1.game.Game;

public abstract class GameObject implements IAttack{
	protected int fila;
	protected int columna;
	protected int vidas;
	private Game game;
	
	public GameObject(Game game, int x, int y, int live) {
		this. fila = x;
		this. columna = y;
		this.setGame(game);
		this.vidas = live;
	}
	
	public int getFil() {
		return fila;
	}
	public int getCol() {
		return columna;
	}
	public void setFil(int fil) {
		this.fila=fil;
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
		return this.fila == x && this.columna == y;
	}
	public void getDamage (int damage) {
		this.vidas-=damage;
	}
	public boolean isOut() {
		return !getGame().isOnBoard(fila, columna);
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
}
