package tp.tp1.game.gameObjects;

import tp.tp1.exceptions.FileContentsException;
import tp.tp1.game.FileContentsVerifier;
import tp.tp1.game.Game;

public final class Ovni extends EnemyShip{
	public final static int PUNTOS_OVNI = 25;
	public final static int VIDA_OVNI = 1;
	
	public Ovni(Game game, int x, int y, int live) {
		super(game, x, y, live);
	}

	public Ovni() {
		super();
	}

	@Override
	public void computerAction() {/*JC*/
		if(IExecuteRandomActions.canGenerateRandomOvni(this.getGame()) && !this.getGame().getHayOvni()) {
			this.getGame().setHayOvni(true);
		}
		
	}
	@Override
	public void onDelete() {
		
		if(getGame().getHayOvni() && this.getVida()<=0) {
			getGame().receivePoints(PUNTOS_OVNI);
			getGame().enableShockWave();
		}
		getGame().setHayOvni(false);
	}

	@Override
	public void move() {
		if(getGame().getHayOvni()) {
			this.setCol(this.getCol() - 1);
		}
	}

	@Override
	public String toString() {
		if(getGame().getHayOvni()) {
			return "O["+this.vidas+"]";
		}else {
			return "";
		}
		
		
	}
	
	public boolean receiveMissileAttack(int damage) {
		boolean dev=false;
		if(getGame().getHayOvni()) {
			this.getDamage(damage);
			dev= true;
		}
		return dev;
	}
	
	
	
	@Override
	public int colAlien() {
		return -1;
	}
	public boolean llegue() {
		return false;
	}
	
	@Override
	public String serialize() {
		return "O;"+this.getGame().getHayOvni()+";"+super.serialize();
	}

	@Override
	protected GameObject parse(String stringFromFile, Game game2, FileContentsVerifier verifier, ListaLabels listaLabel) throws FileContentsException {
		String[] words = stringFromFile.split("\\s*;\\s*");
		if(words[0].equals("O")) {
			if(verifier.verifyOvniString(stringFromFile, game2, VIDA_OVNI)) {
				String[] coords = words[2].split ("\\s*,\\s*");
				GameObject ob= new Ovni(game2,Integer.parseInt(coords[0]) , Integer.parseInt(coords[1]),Integer. parseInt(words[3]));
				game2.setHayOvni(words[1].contentEquals("true"));/*CHAPUZA*/
				return ob;
			}else {
				throw new FileContentsException("incorrect format of arguments in Ovni");
			}
		}else {
			return null;
		}
	}
	
}
