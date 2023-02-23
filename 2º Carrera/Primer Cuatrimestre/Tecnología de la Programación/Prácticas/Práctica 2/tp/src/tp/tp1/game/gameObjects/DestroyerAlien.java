package tp.tp1.game.gameObjects;

import tp.tp1.game.Game;

public final class DestroyerAlien extends AlienShip{
	private boolean disparo;
	public final static int PUNTOS_DESTROYER = 10;
	public final static int VIDA_DESTROYER = 1;
	
	public DestroyerAlien(Game game, int x, int y, int live) {
		super(game, x, y, live);
		disparo=false;
	}

	@Override
	public void computerAction() {
		if(!this.getDisparo() && IExecuteRandomActions.canGenerateRandomBomb(this.getGame())) {
			
			GameObject bomb = new Bomb(this.getGame(), this.fila, this.columna, Bomb.VIDA_BOMBA, this);
			
			this.getGame().getListaObjetos().addFront(bomb);
			this.setDisparo(true);	
		}
	}

	public void setDisparo(boolean b) {
		disparo=b;	
	}

	private boolean getDisparo() {	
		return disparo;
	}

	@Override
	public void onDelete() {
		getGame().receivePoints(PUNTOS_DESTROYER);
		AlienShip.sumarAlien(-1);
		
	}

	@Override
	public String toString() {
		return "D["+this.vidas+"]";
	}
	
	

}
