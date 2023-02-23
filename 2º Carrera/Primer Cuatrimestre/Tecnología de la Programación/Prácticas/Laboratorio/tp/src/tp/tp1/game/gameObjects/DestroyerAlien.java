package tp.tp1.game.gameObjects;

import tp.tp1.exceptions.FileContentsException;
import tp.tp1.game.FileContentsVerifier;
import tp.tp1.game.Game;

public final class DestroyerAlien extends AlienShip{
	private boolean disparo;
	private boolean muerto;
	public final static int PUNTOS_DESTROYER = 10;
	public final static int VIDA_DESTROYER = 1;
	
	public DestroyerAlien(Game game, int x, int y, int live) {
		super(game, x, y, live);
		setDisparo(false);
		setMuerto(false);
	}

	private void setMuerto(boolean b) {
		muerto=b;
		
	}

	public DestroyerAlien() {
		super();
	}

	@Override
	public void computerAction() {
		if(!this.getDisparo() && IExecuteRandomActions.canGenerateRandomBomb(this.getGame())) {
			
			GameObject bomb = new Bomb(this.getGame(), this.getFila(), this.columna, Bomb.VIDA_BOMBA, this);
			
			this.getGame().getListaObjetos().add(bomb);/*QUIZÁS addFront*/
			this.setDisparo(true);	
		}
	}

	public void setDisparo(boolean b) {
		disparo=b;	
	}

	public boolean getDisparo() {	
		return disparo;
	}

	@Override
	public void onDelete() {
		getGame().receivePoints(PUNTOS_DESTROYER);
		AlienShip.sumarAlien(-1);
		setMuerto(true);
	}

	@Override
	public String toString() {
		return "D["+this.vidas+"]";
	}
	private static int currentSerialNumber;

	private void initialiseLabelling() {
		currentSerialNumber = 1;
	}

	private String generateSerializingLabel() {
		if(getDisparo()) {
			label = currentSerialNumber;
			currentSerialNumber++;
			return labelRefSeparator + label;
		}else return "";
	}
	
	public String serialize() {
		if (!getGame().isSerializing()) {
			getGame().setSerializing();
			initialiseLabelling();
		}
		return "D;"+super.serialize() + generateSerializingLabel();
	}

	public boolean isOwner(int ref) {
		boolean itsMe = super.isOwner(ref);
		if (itsMe) setDisparo(true);
		return itsMe;
	}

	
	@Override
	protected GameObject parse(String stringFromFile, Game game2, FileContentsVerifier verifier, ListaLabels listaLabel) throws FileContentsException {
		String[] wordsLabel = stringFromFile.split("\\s*"+ "-" + "\\s*");
		if(wordsLabel.length==1) {
			String[] words = stringFromFile.split("\\s*;\\s*");
			if(words[0].equals("D")) {
				if(verifier.verifyAlienShipString(stringFromFile, game2, VIDA_DESTROYER)) {
					String[] coords = words[1].split ("\\s*,\\s*");
					GameObject ob= new DestroyerAlien(game2,Integer.parseInt(coords[0]) , Integer.parseInt(coords[1]),Integer. parseInt(words[2]));
					((DestroyerAlien) ob).setDisparo(false);
					return ob;
				}else {
					throw new FileContentsException("incorrect format of arguments in Destroyer Alien");
				}
			}else {
				return null;
			}
		}else if(wordsLabel.length==2) {
			String[] words = wordsLabel[0].split("\\s*;\\s*");
			if(words[0].equals("D")) {
				if(verifier.verifyAlienShipString( wordsLabel[0], game2, VIDA_DESTROYER) && verifier.verifyRefString(stringFromFile)) {
					String[] coords = words[1].split ("\\s*,\\s*");
					GameObject ob= new DestroyerAlien(game2,Integer.parseInt(coords[0]) , Integer.parseInt(coords[1]),Integer. parseInt(words[2]));
					((DestroyerAlien) ob).setDisparo(true);
					String[] wordslabel = stringFromFile.split("\\s*"+ "-" + "\\s*");
					Label aux=new Label(Integer.parseInt(wordslabel[1]),null,(DestroyerAlien) ob);

					if(!listaLabel.meter(aux)) {
						throw new FileContentsException("incorrect format of labels between Bombs and DestroyerAliens");
					}
					return ob;
				}else {
					throw new FileContentsException("incorrect format of arguments in Destroyer Alien");
				}
			}else {
				return null;
			}
		}else {
			throw new FileContentsException("incorrect format of arguments in Destroyer Alien");
		}
		
	}

	public boolean getMuerto() {
		return muerto;
	}
	
	
}
