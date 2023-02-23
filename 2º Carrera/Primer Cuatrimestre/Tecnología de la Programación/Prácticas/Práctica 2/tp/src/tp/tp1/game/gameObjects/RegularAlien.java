package tp.tp1.game.gameObjects;

import tp.tp1.game.Game;

public final class RegularAlien extends AlienShip{
	public final static int PUNTOS_REGULAR = 5;
	public final static int VIDA_REGULAR = 2;
	
	public RegularAlien(Game game, int x, int y, int live) {
		super(game, x, y, live);
	}

	@Override
	public void onDelete() {
		getGame().receivePoints(PUNTOS_REGULAR);
		AlienShip.sumarAlien(-1);
		
	}

	
	@Override
	public String toString() {
		return "C["+this.vidas+"]";
	}
	@Override
	
	public void computerAction() {
		if(IExecuteRandomActions.canGenerateRandomExplosive(this.getGame())) {
			GameObject expl=new ExplosiveAlien(getGame(),fila,columna,ExplosiveAlien.VIDA_EXPLOSIVE);
			this.getGame().getListaObjetos().add(expl);
			this.vidas=0;
			getGame().receivePoints(-PUNTOS_REGULAR);
			this.getGame().getListaObjetos().removeDead();
			
		}
	}
	
	
}
