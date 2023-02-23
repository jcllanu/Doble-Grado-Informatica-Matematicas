package tp.tp1.game.gameObjects;

import tp.tp1.exceptions.FileContentsException;
import tp.tp1.exceptions.HyperspaceException;
import tp.tp1.exceptions.OffWorldException;
import tp.tp1.exceptions.WarmUpEngineException;
import tp.tp1.game.FileContentsVerifier;
import tp.tp1.game.Game;
import tp.tp1.game.Mode;

public final class UCMShip extends Ship{
	public final static int VIDA_UCM = 3;
	public final static int COL_INI_UCM = 4;
	private Mode hyperspace;
	
	public UCMShip(Game game, int x, int y, int live) {
		super(game, x, y, live);
		setHyperspace(Mode.OFF);
	}

	public UCMShip() {
		super();
	}

	@Override
	public void computerAction() {
		
	}

	@Override
	public void onDelete() {
		
	}

	@Override
	public void move(){
		
	}

	@Override
	public String toString() {
		String devuelve;
		if(this.vidas>0) {
			devuelve="^__^";
		}else {
			devuelve="!xx!";
		}
		return devuelve;
	}
	
	
	public boolean receiveBombAttack(int damage) {
		this.getDamage(damage);
		return true;
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
		return "P;"+super.serialize()+";"+this.getGame().getPuntos()+";"+this.getGame().getShockWave()+";"+UCMShipSuperMisil.getNumSuperMisil();
	}

	@Override
	protected GameObject parse(String stringFromFile, Game game2, FileContentsVerifier verifier, ListaLabels listaLabel) throws FileContentsException {
		String[] words = stringFromFile.split("\\s*;\\s*");
		if(words[0].equals("P")) {
			if(verifier.verifyPlayerString(stringFromFile, game2, VIDA_UCM)) {
				String[] coords = words[1].split ("\\s*,\\s*");
				GameObject ob= new UCMShip(game2,Integer.parseInt(coords[0]) , Integer.parseInt(coords[1]),Integer. parseInt(words[2]));
				UCMShipSuperMisil.setNumSuperMisil(Integer.parseInt(words[5]));
				game2.setPuntos(Integer.parseInt(words[3]));
				game2.setShockWave(words[4].contentEquals("true"));
				game2.setNave((UCMShip)ob);
				return ob;
			}else {
				throw new FileContentsException("incorrect format of arguments in UCMShip");
			}
		}else {
			return null;
		}
	}

	public Mode getHyperspace() {
		return hyperspace;
	}

	public void setHyperspace(Mode hyperspace) {
		this.hyperspace = hyperspace;
	}
	
}
