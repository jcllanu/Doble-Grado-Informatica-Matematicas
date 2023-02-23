package tp.tp1.game.gameObjects;

import tp.tp1.game.Game;

public interface IExecuteRandomActions {
	public final static int PROB_EXPLOSIVE=5;
	static boolean canGenerateRandomOvni(Game game){
		int a;
		double b;
		a=game.getRandom().nextInt(10);
		b=  game.getLevel().getFrecuenciaOvni()*10;
		
		return a < (int) b;
	}
	static boolean canGenerateRandomBomb(Game game){
		int a;
		double b;
		a=game.getRandom().nextInt(10);
		b=  game.getLevel().getFrecuenciaDisp()*10;
		
		return a < (int) b;
	}
	static boolean canGenerateRandomExplosive(Game game){
		int a, b;
		a=game.getRandom().nextInt(100);
		b=  PROB_EXPLOSIVE;
		
		return a < b;
	}

}
