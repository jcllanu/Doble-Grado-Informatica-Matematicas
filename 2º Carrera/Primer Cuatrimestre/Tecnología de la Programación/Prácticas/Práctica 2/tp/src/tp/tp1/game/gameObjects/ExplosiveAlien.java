package tp.tp1.game.gameObjects;

import tp.tp1.game.Game;


public class ExplosiveAlien extends AlienShip{
	public final static int PUNTOS_EXPLOSIVE = 5;
	public final static int VIDA_EXPLOSIVE = 2;
	public final static int DANNO_EXPLOSIVE = 1;
	
	public ExplosiveAlien(Game game, int x, int y, int live) {
		super(game, x, y, live);
	}

	@Override
	public void computerAction() {

	}

	@Override
	public void onDelete() {
		getGame().receivePoints(PUNTOS_EXPLOSIVE);
		AlienShip.sumarAlien(-1);
		for(int i=-1; i<2; i++) {
			for(int j=-1; j<2; j++) {
				if(i!= 0||j!=0) {
					if(this.getGame().getListaObjetos().getObjectInPosition(fila+i,columna+j)!=null) {
						this.performAttack(this.getGame().getListaObjetos().getObjectInPosition(fila+i,columna+j));
					}
					
				}
			}
			
		}
		
	}

	public boolean performAttack(GameObject other) {
		if(this.vidas<=0) {
			return other.receiveExplosiveAttack(DANNO_EXPLOSIVE);
		}
		return false;
		
	}
	@Override
	public String toString() {
		return "E["+this.vidas+"]";
	}
	
	
}
