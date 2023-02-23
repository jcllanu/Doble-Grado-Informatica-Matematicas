package tp.tp1.game.gameObjects;

import tp.tp1.game.Game;

public abstract class Ship extends GameObject{

	public Ship(Game game, int x, int y, int live) {
		super(game, x, y, live);
	}

	public Ship() {
		
	}
	public String serialize() {
		return getFila()+","+columna+";"+vidas;
	}
}
