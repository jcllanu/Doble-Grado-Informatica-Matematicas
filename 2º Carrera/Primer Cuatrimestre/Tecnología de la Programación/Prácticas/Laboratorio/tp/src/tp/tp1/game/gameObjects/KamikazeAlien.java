package tp.tp1.game.gameObjects;

import tp.tp1.exceptions.FileContentsException;
import tp.tp1.game.FileContentsVerifier;
import tp.tp1.game.Game;

public class KamikazeAlien extends AlienShip{
	public final static int PUNTOS_KAMIKAZE = 5;
	public final static int VIDA_KAMIKAZE = 1;
	public final static int DANNO_KAMIKAZE = 2;
	
	public KamikazeAlien(Game game, int x, int y, int live) {
		super(game, x, y, live);
	}

	public KamikazeAlien() {
		super();
	}

	@Override
	public void onDelete() {
		getGame().receivePoints(PUNTOS_KAMIKAZE);
		AlienShip.sumarAlien(-1);
		
	}

	public void move() {
		if(this.getGame().getCiclos()%2==0) {
			this.setFil(this.getFil()+1);
			int dif=this.getCol()-this.getGame().getNave().getCol();
			if(dif>0) {
				this.setCol(this.getCol()-1);
			}else if(dif<0) {
				this.setCol(this.getCol()+1);
			}
		}
		
	}
	public boolean performAttack(GameObject other) {
		boolean dev=false;
		if(other.isOnPosition(this.getFila(),this.columna)) {
			dev= other.receiveBombAttack(DANNO_KAMIKAZE);
		}
	
		return dev;
	}
	@Override
	public String toString() {
		return "K["+this.vidas+"]";
	}
	@Override
	
	public void computerAction() {
		
	}
	
	@Override
	protected GameObject parse(String stringFromFile, Game game2, FileContentsVerifier verifier, ListaLabels listaLabel) throws FileContentsException {
		String[] words = stringFromFile.split("\\s*;\\s*");
		if(words[0].equals("K")) {
			if(verifier.verifyAlienShipString(stringFromFile, game2, VIDA_KAMIKAZE)) {
				String[] coords = words[1].split ("\\s*,\\s*");
				GameObject ob= new RegularAlien(game2,Integer.parseInt(coords[0]) , Integer.parseInt(coords[1]),Integer. parseInt(words[2]));
				return ob;
			}else {
				throw new FileContentsException("incorrect format of arguments in Kamikaze Alien");
			}
		}else {
			return null;
		}
	}

	@Override
	public String serialize() {
		return "K;"+super.serialize();
	}
	
}
