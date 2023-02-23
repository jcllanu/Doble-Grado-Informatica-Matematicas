package tp.tp1.game.gameObjects;

import tp.tp1.game.Game;

public abstract class Weapon extends GameObject{

	public Weapon(Game game, int x, int y, int live) {
		super(game, x, y, live);
	}
	public Weapon() {
		super();
	}
	@Override
	public void computerAction() {
		
	}
	@Override
	public int colAlien() {
		return -1;
	}
	public boolean llegue() {
		return false;
	}
	public String serialize() {
		return getFila()+","+columna;
	}
}
