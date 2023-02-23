package tp.tp1.game.gameObjects;

import tp.tp1.game.FileContentsVerifier;
import tp.tp1.game.Game;

public final class Shockwave extends Weapon{
	public final static int DANNO_SHOCKWAVE=1;
	public Shockwave(Game game, int x, int y, int live) {
		super(game, x, y, live);
	}

	public Shockwave() {
		super();
	}

	@Override
	public void computerAction() {
		
	}

	@Override
	public void onDelete() {
		
	}

	@Override
	public void move() {
		
	}
	public boolean performAttack(GameObject other) {
		return other.receiveShockWaveAttack(DANNO_SHOCKWAVE);
	}
	@Override
	public String toString() {
		return "";
	}
	
	@Override
	public String serialize() {
		return "";
	}

	@Override
	protected GameObject parse(String stringFromFile, Game game2, FileContentsVerifier verifier, ListaLabels listaLabel) {
		return null;
	}
	
}
