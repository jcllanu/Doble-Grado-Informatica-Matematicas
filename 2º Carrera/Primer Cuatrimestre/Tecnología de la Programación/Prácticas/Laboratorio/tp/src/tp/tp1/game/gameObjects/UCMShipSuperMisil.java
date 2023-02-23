package tp.tp1.game.gameObjects;

import tp.tp1.exceptions.FileContentsException;
import tp.tp1.game.FileContentsVerifier;
import tp.tp1.game.Game;

public class UCMShipSuperMisil extends UCMShipLaser {
	public final static int DANNO_LASER = 2;
	private static int numSuperMisil;
	
	public UCMShipSuperMisil(Game game, int x, int y, int live) {
		super(game, x, y, live);
	}

	public UCMShipSuperMisil() {
		super();
	}

	public boolean performAttack(GameObject other) {
		if(other.isOnPosition(this.getFila(),this.columna)) {
			return other.receiveMissileAttack(DANNO_LASER);
		}
	
		return false;
	}
	
	@Override
	public String toString() {
		return "บบ";
	}

	public static int getNumSuperMisil() {
		return numSuperMisil;
	}

	public static void setNumSuperMisil(int numSuperMisil) {
		UCMShipSuperMisil.numSuperMisil = numSuperMisil;
	}
	public String serialize() {
		return "X"+super.serialize();
	}
	@Override
	protected GameObject parse(String stringFromFile, Game game2, FileContentsVerifier verifier, ListaLabels listaLabel) throws FileContentsException {
		String[] words = stringFromFile.split("\\s*;\\s*");
		if(words[0].equals("XM")) {
			if(!verifier.isMissileOnLoadedBoard()) {
				if(verifier.verifyWeaponString(stringFromFile, game2)) {
			
				String[] coords = words[1].split ("\\s*,\\s*");
				GameObject ob= new UCMShipSuperMisil(game2,Integer.parseInt(coords[0]) , Integer.parseInt(coords[1]),1);
				return ob;
				}else {
					throw new FileContentsException("incorrect format of arguments in SuperMisil");
				}
			}else {
				throw new FileContentsException("two Lasers on board");
			}
		}else {
			return null;
		}
	}
}
