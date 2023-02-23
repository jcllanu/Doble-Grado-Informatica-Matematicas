package tp.tp1.game.gameObjects;

import tp.tp1.exceptions.FileContentsException;
import tp.tp1.game.FileContentsVerifier;
import tp.tp1.game.Game;
;

public final class Bomb extends Weapon{

	public static final int DANNO_BOMBA = 1;
	public static final int VIDA_BOMBA = 1;
	private DestroyerAlien padre;
	public Bomb(Game game, int x, int y, int live, DestroyerAlien padr) {
		super(game, x, y, live);
		setPadre(padr);
	}


	public Bomb() {
		super();
	}


	@Override
	public void onDelete() {
		if(getPadre()!=null) {
			getPadre().setDisparo(false);
		}
		
	}

	@Override
	public void move() {
		this.setFil(this.getFil() + 1);
	}

	

	@Override
	public String toString() {
		return ".";
	}
	public boolean performAttack(GameObject other) {
		boolean dev=false;
		if(other.isOnPosition(this.getFila(),this.columna)) {
			dev= other.receiveBombAttack(DANNO_BOMBA);
		}
	
		return dev;
	}
	
	public boolean receiveMissileAttack(int damage) {
		this.getDamage(damage);
		return true;
	}


	// call to getLabel assumes owner already serialized (so label already generated)
		public String generateSerialRef() {
			if(getPadre()!=null && !getPadre().getMuerto()) {
				return labelRefSeparator + getPadre().getLabel();
			}else {
				return "";
			}
		}

		public String serialize() {
			return "B;"+super.serialize() + generateSerialRef();
		}
	
		// call to getBombOwner assumes owner already deserialized (so ref points to valid object)
		/*public Bomb createInstance(Game game, int x, int y) {
			return new Bomb(game, x, y, game.getBombOwner(ownerRef));
		}*/


		@Override
		protected GameObject parse(String stringFromFile, Game game2, FileContentsVerifier verifier, ListaLabels listaLabel) throws FileContentsException {
			String[] wordsLabel = stringFromFile.split("\\s*"+ "-" + "\\s*");
			if(wordsLabel.length==1) {
				String[] words = stringFromFile.split("\\s*;\\s*");
				if(words[0].equals("B")) {
					if(verifier.verifyWeaponString(stringFromFile, game2)) {
						String[] coords = words[1].split ("\\s*,\\s*");
						GameObject ob= new Bomb(game2,Integer.parseInt(coords[0]) , Integer.parseInt(coords[1]),1,null);
						return ob;
					}else {
						throw new FileContentsException("incorrect format of arguments in Bomb");
					}
				}else {
					return null;
				}
			}else if(wordsLabel.length==2) {
				String[] words = wordsLabel[0].split("\\s*;\\s*");
				if(words[0].equals("B")) {
					if(verifier.verifyWeaponString(wordsLabel[0], game2) && verifier.verifyRefString(stringFromFile)) {
						String[] coords = words[1].split ("\\s*,\\s*");
						GameObject ob= new Bomb(game2,Integer.parseInt(coords[0]) , Integer.parseInt(coords[1]),1,null);
						String[] wordslabel = stringFromFile.split("\\s*"+ "-" + "\\s*");
						Label aux=new Label(Integer.parseInt(wordslabel[1]),(Bomb) ob,null);
						
						if(!listaLabel.meter(aux)) {
							throw new FileContentsException("incorrect format of labels between Bombs and DestroyerAliens");
						}
						return ob;
					}else {
						throw new FileContentsException("incorrect format of arguments in Bomb");
					}
				}else {
					return null;
				}
			}else {
				throw new FileContentsException("incorrect format of arguments in Bomb");
			}
			
		}


		public DestroyerAlien getPadre() {
			return padre;
		}


		public void setPadre(DestroyerAlien padre) {
			this.padre = padre;
		}


		
}