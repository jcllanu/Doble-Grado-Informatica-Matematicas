package tp.tp1.view;

import tp.tp1.game.Game;

public abstract class GamePrinter {
	protected Game game;
	
	public void setGame(Game g) {
		game=g;
		this.prepareToString(g);
	}
	protected abstract void prepareToString(Game g);
}
