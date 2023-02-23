package tp.tp1.game.gameObjects;

import tp.tp1.game.Game;
;

public final class Bomb extends Weapon{

	public static final int DANNO_BOMBA = 1;
	public static final int VIDA_BOMBA = 1;
	private DestroyerAlien padre;
	public Bomb(Game game, int x, int y, int live, DestroyerAlien padr) {
		super(game, x, y, live);
		padre=padr;
	}


	@Override
	public void onDelete() {
		if(padre!=null) {
			padre.setDisparo(false);
		}
		
	}

	@Override
	public void move() {
		this.setFil(this.getFil() + 1);
	}

	

	@Override
	public String toString() {
		return ".";
	}
	public boolean performAttack(GameObject other) {
		boolean dev=false;
		if(other.isOnPosition(this.fila,this.columna)) {
			dev= other.receiveBombAttack(DANNO_BOMBA);
		}
	
		return dev;
	}
	
	public boolean receiveMissileAttack(int damage) {
		this.getDamage(damage);
		return true;
	}
	

}
