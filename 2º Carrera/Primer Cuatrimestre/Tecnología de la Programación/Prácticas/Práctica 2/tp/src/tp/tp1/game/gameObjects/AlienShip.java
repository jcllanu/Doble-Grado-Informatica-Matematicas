package tp.tp1.game.gameObjects;

import tp.tp1.game.Game;
import tp.tp1.game.Move;

public abstract class AlienShip extends EnemyShip{
	private static boolean hanLlegado=false;
	private static int numAlien;

	
	public AlienShip(Game game, int x, int y, int live) {
		super(game, x, y, live);
		numAlien++;
	}
	
	public void move() {
		if(this.getGame().getMove().equals(Move.DOWN)) {
			this.setFil(this.getFil() + 1);
		}
		else if(this.getGame().getCiclos()%this.getGame().getLevel().getVelocidad()==0) {
			
			if(this.getGame().getMove().equals(Move.RIGHT)) {
				this.setCol(this.getCol() + 1);
			}
			else if(this.getGame().getMove().equals(Move.LEFT)) {
				this.setCol(this.getCol() - 1);
			}
		}
		
		
	}
	public boolean receiveMissileAttack(int damage) {
		this.getDamage(damage);
		return true;
	}
	public static boolean haveLanded() {
		return hanLlegado;
	}
	public static void sethaveLanded(boolean b) {
		hanLlegado=b;
	}
	public static void sumarAlien(int n) {
		setNumAlien(getNumAlien() + n);
	}
	public static boolean allDead() {
		return getNumAlien()<=0;
	}

	
	@Override
	public int colAlien() {
		return this.columna;
	}
	
	public boolean receiveShockWaveAttack(int damage) {
		this.getDamage(damage);
		return true;
	}

	public static int getNumAlien() {
		return numAlien;
	}

	public static void setNumAlien(int numAlien) {
		AlienShip.numAlien = numAlien;
	}
	public boolean llegue() {
		return this.getFil()==Game.NUM_FILAS-1;
	}
}














