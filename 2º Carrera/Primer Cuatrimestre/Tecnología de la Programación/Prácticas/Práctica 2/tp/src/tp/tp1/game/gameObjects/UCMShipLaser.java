package tp.tp1.game.gameObjects;

import tp.tp1.game.Game;

public class UCMShipLaser extends Weapon{
	public final static int DANNO_LASER = 1;
	
	public UCMShipLaser(Game game, int x, int y, int live) {
		super(game, x, y, live);
	}

	@Override
	public void onDelete() {
		getGame().enableMissile();
	}

	@Override
	public void move() {
		this.setFil(getFil()-1);
		
	}
	public boolean performAttack(GameObject other) {
		boolean dev=false;
		if(other.isOnPosition(this.fila,this.columna)) {
			dev= other.receiveMissileAttack(DANNO_LASER);
		}
	
		return dev;
	}
	@Override
	public String toString() {
		return "oo";
	}

	public boolean receiveBombAttack(int damage) {
		this.getDamage(damage);

		return true;
	}
	
}
