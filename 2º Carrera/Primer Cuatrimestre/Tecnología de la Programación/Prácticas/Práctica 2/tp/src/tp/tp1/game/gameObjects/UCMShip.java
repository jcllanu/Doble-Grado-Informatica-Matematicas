package tp.tp1.game.gameObjects;

import tp.tp1.game.Game;

public final class UCMShip extends Ship{
	public final static int VIDA_UCM = 3;
	public final static int COL_INI_UCM = 4;
	
	public UCMShip(Game game, int x, int y, int live) {
		super(game, x, y, live);
		
	}

	@Override
	public void computerAction() {
		
	}

	@Override
	public void onDelete() {
		
	}

	@Override
	public void move() {
		this.getGame().move(0);
		
	}

	@Override
	public String toString() {
		String devuelve;
		if(this.vidas>0) {
			devuelve="^__^";
		}else {
			devuelve="!xx!";
		}
		return devuelve;
	}
	
	
	public boolean receiveBombAttack(int damage) {
		this.getDamage(damage);
		return true;
	}
	

	@Override
	public int colAlien() {
		
		return -1;
	}
	public boolean llegue() {
		return false;
	}

}
