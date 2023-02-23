package tp.tp1.game.gameObjects;

import tp.tp1.game.Game;
import tp.tp1.game.gameObjects.lists.GameObjectBoard;
import tp.tp1.Level;
/*import tp.tp1.game.GameObjects.Lists.GameObjectBoard;*/

public class BoardInitializer {
	private Level level;
	private GameObjectBoard board;
	private Game game;
	
	
	
	public GameObjectBoard initialize(Game game, Level level) {
		this.level = level;
		this. game = game;
		board = new GameObjectBoard(Game.NUM_FILAS, Game.NUM_COLUMNAS,game);
		
		initializeOvni (game);
		initializeRegularAliens ();
		initializeDestroyerAliens ();
		initializeBarriers();
		return board;
	}
	
	private void initializeBarriers() {
		for(int i=0; i<this.level.getBarriers(); i++) {
			GameObject barrier=new Barrier(this.game,Game.NUM_FILAS-2,this.level.getcolPrimBarriers()+this.level.getSeparacionBarriers()*i,
					Barrier.VIDA_BARRIER);
			board.add(barrier);
		}
		
	}

	public void initializeOvni(Game g) {
		this.game=g;
		if(g.getListaObjetos()!=null) {
			this.board=g.getListaObjetos();
		}
		this.level=g.getLevel();
		game.setHayOvni(false);
		GameObject ovni=new Ovni(this.game, 0, Game.NUM_COLUMNAS, Ovni.VIDA_OVNI);
		board.add(ovni);
	}
	
	private void initializeRegularAliens () {
		
		for(int i=0; i<this.level.getRegular(); i++) {
			GameObject regular=new RegularAlien(this.game,1+i/4,3+i%4,RegularAlien.VIDA_REGULAR);
			board.add(regular);
		}
		
	}
	private void initializeDestroyerAliens () {
		for(int i=0; i<this.level.getDestroyers();i++) {
			GameObject destroyer=new DestroyerAlien(this.game,level.filDestroyer(),level.colFirstDestroyer()+i,DestroyerAlien.VIDA_DESTROYER);
			board.add(destroyer);
		}
	}
}
