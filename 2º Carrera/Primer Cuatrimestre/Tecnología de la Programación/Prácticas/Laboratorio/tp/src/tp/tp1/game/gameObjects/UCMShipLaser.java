package tp.tp1.game.gameObjects;

import tp.tp1.exceptions.FileContentsException;
import tp.tp1.game.FileContentsVerifier;
import tp.tp1.game.Game;

public class UCMShipLaser extends Weapon{
	public final static int DANNO_LASER = 1;
	
	public UCMShipLaser(Game game, int x, int y, int live) {
		super(game, x, y, live);
	}

	public UCMShipLaser() {
		super();
	}

	@Override
	public void onDelete() {
		getGame().enableMissile();
	}

	@Override
	public void move() {
		this.setFil(getFil()-1);
		
	}
	public boolean performAttack(GameObject other) {
		boolean dev=false;
		if(other.isOnPosition(this.getFila(),this.columna)) {
			dev= other.receiveMissileAttack(DANNO_LASER);
		}
	
		return dev;
	}
	@Override
	public String toString() {
		return "oo";
	}

	public boolean receiveBombAttack(int damage) {
		this.getDamage(damage);

		return true;
	}

	@Override
	public String serialize() {
		return "M;"+super.serialize();
	}

	@Override
	protected GameObject parse(String stringFromFile, Game game2, FileContentsVerifier verifier, ListaLabels listaLabel) throws FileContentsException {
		String[] words = stringFromFile.split("\\s*;\\s*");
		if(words[0].equals("M")) {
			if(!verifier.isMissileOnLoadedBoard()) {
				if(verifier.verifyWeaponString(stringFromFile, game2)) {
			
				String[] coords = words[1].split ("\\s*,\\s*");
				GameObject ob= new UCMShipLaser(game2,Integer.parseInt(coords[0]) , Integer.parseInt(coords[1]),1);
				return ob;
				}else {
					throw new FileContentsException("incorrect format of arguments in Laser");
				}
			}else {
				throw new FileContentsException("two Lasers on board");
			}
		}else {
			return null;
		}
	}
	
}
