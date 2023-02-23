package tp.tp1.game.gameObjects;

import tp.tp1.exceptions.FileContentsException;
import tp.tp1.game.FileContentsVerifier;
import tp.tp1.game.Game;

public class Barrier extends GameObject{
	public final static int VIDA_BARRIER = 8;
	
	public Barrier(Game game, int x, int y, int live) {
		super(game, x, y, live);
	}

	public Barrier() {
		super();
	}

	@Override
	public void onDelete() {
	}

	
	@Override
	public String toString() {
		return "S["+this.vidas+"]";
	}
	@Override
	
	public void computerAction() {
		
	}
	public boolean receiveMissileAttack(int damage) {
		this.getDamage(damage);
		return true;
	}
	public boolean receiveBombAttack(int damage) {
		this.getDamage(damage);
		return true;
	}
	
	@Override
	protected GameObject parse(String stringFromFile, Game game2, FileContentsVerifier verifier, ListaLabels listaLabel) throws FileContentsException {
		String[] words = stringFromFile.split("\\s*;\\s*");
		if(words[0].equals("S")) {
			if(verifier.verifyAlienShipString(stringFromFile, game2, VIDA_BARRIER)) {
				String[] coords = words[1].split ("\\s*,\\s*");
				GameObject ob= new Barrier(game2,Integer.parseInt(coords[0]) , Integer.parseInt(coords[1]),Integer. parseInt(words[2]));
				return ob;
			}else {
				throw new FileContentsException("incorrect format of arguments in Barrier");
			}
		}else {
			return null;
		}
	}

	@Override
	public String serialize() {
		return "S;"+fila+","+columna+";"+vidas;
	}

	@Override
	public void move() {
	}

	@Override
	public int colAlien() {
		return -1;
	}

	@Override
	public boolean llegue() {
		return false;
	}
	
}
