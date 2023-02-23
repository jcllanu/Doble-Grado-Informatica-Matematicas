package tp.tp1.game.gameObjects;

import tp.tp1.game.Game;

public final class Ovni extends EnemyShip{
	public final static int PUNTOS_OVNI = 25;
	public final static int VIDA_OVNI = 1;
	
	public Ovni(Game game, int x, int y, int live) {
		super(game, x, y, live);
	}

	@Override
	public void computerAction() {/*JC*/
		if(IExecuteRandomActions.canGenerateRandomOvni(this.getGame()) && !this.getGame().getHayOvni()) {
			this.getGame().setHayOvni(true);
		}
		
	}
	@Override
	public void onDelete() {
		
		if(getGame().getHayOvni() && this.getVida()<=0) {
			getGame().receivePoints(PUNTOS_OVNI);
			getGame().enableShockWave();
		}
		getGame().setHayOvni(false);
	}

	@Override
	public void move() {
		if(getGame().getHayOvni()) {
			this.setCol(this.getCol() - 1);
		}
	}

	@Override
	public String toString() {
		if(getGame().getHayOvni()) {
			return "O["+this.vidas+"]";
		}else {
			return "";
		}
		
		
	}
	
	public boolean receiveMissileAttack(int damage) {
		boolean dev=false;
		if(getGame().getHayOvni()) {
			this.getDamage(damage);
			dev= true;
		}
		return dev;
	}
	
	
	
	@Override
	public int colAlien() {
		return -1;
	}
	public boolean llegue() {
		return false;
	}
}
