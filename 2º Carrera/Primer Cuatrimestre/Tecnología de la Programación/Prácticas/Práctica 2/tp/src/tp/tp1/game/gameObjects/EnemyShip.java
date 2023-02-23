package tp.tp1.game.gameObjects;

import tp.tp1.game.Game;

public abstract class EnemyShip extends Ship  implements IExecuteRandomActions{

	public EnemyShip(Game game, int x, int y, int live) {
		super(game, x, y, live);
	}
	
	

}
