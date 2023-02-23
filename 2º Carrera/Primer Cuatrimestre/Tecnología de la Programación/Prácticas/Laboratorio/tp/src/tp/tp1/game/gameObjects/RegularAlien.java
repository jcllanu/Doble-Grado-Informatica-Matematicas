package tp.tp1.game.gameObjects;

import tp.tp1.exceptions.FileContentsException;
import tp.tp1.game.FileContentsVerifier;
import tp.tp1.game.Game;

public final class RegularAlien extends AlienShip{
	public final static int PUNTOS_REGULAR = 5;
	public final static int VIDA_REGULAR = 2;
	
	public RegularAlien(Game game, int x, int y, int live) {
		super(game, x, y, live);
	}

	public RegularAlien() {
		super();
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
			GameObject expl=new ExplosiveAlien(getGame(),getFila(),columna,ExplosiveAlien.VIDA_EXPLOSIVE);
			this.getGame().getListaObjetos().add(expl);
			this.vidas=0;
			getGame().receivePoints(-PUNTOS_REGULAR);
			this.getGame().getListaObjetos().removeDead();
			
		}
	}
	
	@Override
	protected GameObject parse(String stringFromFile, Game game2, FileContentsVerifier verifier, ListaLabels listaLabel) throws FileContentsException {
		String[] words = stringFromFile.split("\\s*;\\s*");
		if(words[0].equals("R")) {
			if(verifier.verifyAlienShipString(stringFromFile, game2, VIDA_REGULAR)) {
				String[] coords = words[1].split ("\\s*,\\s*");
				GameObject ob= new RegularAlien(game2,Integer.parseInt(coords[0]) , Integer.parseInt(coords[1]),Integer. parseInt(words[2]));
				return ob;
			}else {
				throw new FileContentsException("incorrect format of arguments in Regular Alien");
			}
		}else {
			return null;
		}
	}

	@Override
	public String serialize() {
		return "R;"+super.serialize();
	}
	
}
