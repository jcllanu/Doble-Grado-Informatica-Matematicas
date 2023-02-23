package tp.tp1.game.gameObjects;

import tp.tp1.game.Game;

public class UCMShipSuperMisil extends UCMShipLaser {
	public final static int DANNO_LASER = 2;
	private static int numSuperMisil;
	
	public UCMShipSuperMisil(Game game, int x, int y, int live) {
		super(game, x, y, live);
	}

	public boolean performAttack(GameObject other) {
		if(other.isOnPosition(this.fila,this.columna)) {
			return other.receiveMissileAttack(DANNO_LASER);
		}
	
		return false;
	}
	
	@Override
	public String toString() {
		return "บบ";
	}

	public static int getNumSuperMisil() {
		return numSuperMisil;
	}

	public static void setNumSuperMisil(int numSuperMisil) {
		UCMShipSuperMisil.numSuperMisil = numSuperMisil;
	}
}
