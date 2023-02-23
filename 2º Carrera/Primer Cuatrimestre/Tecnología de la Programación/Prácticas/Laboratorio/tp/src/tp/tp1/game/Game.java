package tp.tp1.game;

import tp.tp1.Level;
import tp.tp1.exceptions.*;
import tp.tp1.game.gameObjects.AlienShip;
import tp.tp1.game.gameObjects.BoardInitializer;
import tp.tp1.game.gameObjects.DestroyerAlien;
import tp.tp1.game.gameObjects.GameObject;
import tp.tp1.game.gameObjects.GameObjectGenerator;
import tp.tp1.game.gameObjects.IPlayerController;
import tp.tp1.game.gameObjects.ListaLabels;
import tp.tp1.game.gameObjects.UCMShip;
import tp.tp1.game.gameObjects.UCMShipLaser;
import tp.tp1.game.gameObjects.UCMShipSuperMisil;
import tp.tp1.game.gameObjects.lists.GameObjectBoard;

import java.io.BufferedReader;
import java.io.IOException;
import java.util.Random;



public class Game implements IPlayerController{
	
	public final static int NUM_FILAS = 8;
	public final static int NUM_COLUMNAS = 9;
	private Level level;
	private Random rand;
	private Move move;
	private int ciclos;
	private int puntos;
	private boolean shockWave;
	private boolean missile;
	private boolean hayOvni;
	private BoardInitializer initializer;
	private	UCMShip nave;
	private GameObjectBoard listaObjetos;
	
	
	
	//MÉTODOS DE INICIO DE PARTIDA
	public Game(Level level, Random random){
		this.rand = random;
		this.level = level;
		initializer = new BoardInitializer();
		initGame();
	}
	
	public Game() {
		
	}

	public void initGame() {
		this.move=Move.LEFT;
		this.setCiclos(0);
		this.setPuntos(0);
		AlienShip.setNumAlien(0);
		UCMShipSuperMisil.setNumSuperMisil(0);
		
		this.listaObjetos= getInitializer().initialize (this, level);
		this.nave = new UCMShip(this, NUM_FILAS-1, UCMShip.COL_INI_UCM, UCMShip.VIDA_UCM);
		this.listaObjetos.add(this.nave);
	}
	
	//MÉTODOS DE PINTADO DE PARTIDA
	
	public String characterAtToString(int i, int j) { //Devuelve el string del personaje en la posición i,j
		return listaObjetos.toString(i, j);
	}

	public String data() {
		String text = new String();
		text = " \nLife: " + nave.getVida() + "\nNumber of cycles: " + getCiclos() + "\nPoints: " +
				getPuntos() +"\nRemaining aliens: "+ AlienShip.getNumAlien();

		if(getShockWave()){
			text+="\nshockWave: SI";
		}else {
			text+="\nshockWave: NO";
		}
		text+="\nSupermissiles: " + UCMShipSuperMisil.getNumSuperMisil();
		return text;
	}
	
	
	//MÉTODOS LLAMADOS DESDE LOS COMANDOS
	@Override
	public void move(int numCells) throws OffWorldException {/*IGUAL HAY QUE IMPLEMENTAR ESTO EN UCMShip*/

		if(!(nave.getCol() + numCells < 0 || nave.getCol() + numCells >=NUM_COLUMNAS)) {
			nave.setCol(nave.getCol() + numCells);
		}else {
			throw new OffWorldException("You can't move that far. You would be out off world.");
		}

	}


	@Override
	public void shockWave() throws NoShockwaveException{
	
		
		if(	this.getShockWave()) {
			this.listaObjetos.shockWaveAttack();
			this.setShockWave(false);
		}else {
			throw new NoShockwaveException("You don't have any ShockWave avaliable");
			
		}
	}
	
	@Override
	public void shootLaser(boolean supermisil) throws MissileInFlightException, NoAvailableSupermissileException {
		GameObject mis;
		if(!this.missile) {
			if(!supermisil) {
				mis=new UCMShipLaser(this,this.nave.getFil(),this.nave.getCol(),1);
				this.listaObjetos.addFront(mis);
				this.missile=true;
				
			}else {
				if(UCMShipSuperMisil.getNumSuperMisil()>0) {
					mis=new UCMShipSuperMisil(this,this.nave.getFil(),this.nave.getCol(),1);
					UCMShipSuperMisil.setNumSuperMisil(UCMShipSuperMisil.getNumSuperMisil()-1);
					this.listaObjetos.addFront(mis);
					this.missile=true;
				}else {
					throw new NoAvailableSupermissileException("You don't have any SuperMissile available");
				}
			}
		}else {
			throw new MissileInFlightException("There's already a missile in flight.");
		}
		
	}
	
	public void buySuperMissile() throws NotEnoughPointsException{
		
		if (this.getPuntos() >= 20) {
			this.setPuntos(this.getPuntos() - 20);
			UCMShipSuperMisil.setNumSuperMisil(UCMShipSuperMisil.getNumSuperMisil() + 1);
		}else {
			throw new NotEnoughPointsException("Not enough points to buy the SuperMissile");
		}
	
	}

	public void rotate(boolean derecha) throws OffWorldException {
		if(!this.listaObjetos.rotate(derecha)) {
			throw new OffWorldException("Some ships wouldn't fit in the board"); 
		}
		
	}
	private boolean serializing = false;
	
	public void setSerializing() {
		serializing = true;
	}
	
	public boolean isSerializing() {
		return serializing;
	}

	public String serialize() {
		serializing = false;
		String dev="G;"+ ciclos+";"+level+";"+move;
		dev+= listaObjetos.serialize();
	
		return dev;
	}
	public DestroyerAlien getBombOwner(int ref) {
		return (DestroyerAlien) listaObjetos.getLabelOwner(ref);  // ugly cast
	}
	
	public void load(BufferedReader bf) throws FileContentsException {/*REVISAR*/
		
		boolean loading = false;
		String line=null;
		FileContentsVerifier verifier = new FileContentsVerifier();
		try {
			line = bf.readLine().trim();
			String[] words = line.split ("\\s*;\\s*");
			if(words.length!=4) {
				throw new FileContentsException("Invalid file, " + "incorrect format of arguments in Game");
			}
			if(!FileContentsVerifier.verifyCurrentCycle(Integer.parseInt(words[1]))||!FileContentsVerifier.verifyLevel(Level.parse(words[2]))||!FileContentsVerifier.verifyDir(Move.parse(words[3]))) {
				throw new FileContentsException("Invalid file, " + "incorrect format of arguments in Game");
			}else {
				ciclos=Integer.parseInt(words[1]);
				move=Move.parse(words[3]);
				level=Level.parse(words[2]);
				rand = new Random(System.currentTimeMillis());
				initializer = new BoardInitializer();
				line = bf.readLine().trim();
				
			}
		} catch (IOException e) {
			throw new FileContentsException("Error while reading the file");
			
		}
		AlienShip.setNumAlien(0);
		UCMShipSuperMisil.setNumSuperMisil(0);
		listaObjetos=new GameObjectBoard (NUM_FILAS, NUM_COLUMNAS, this);
		ListaLabels listaLabel =new ListaLabels();
		while( line != null && !line.isEmpty() ) {
			try {
				GameObject gameObject = GameObjectGenerator.parse(line, this, verifier,listaLabel);
				if (gameObject == null) {
					throw new FileContentsException("Invalid file, " + "unrecognised line prefix");
				}
				
				listaObjetos.add(gameObject);
				line = bf.readLine().trim();
			}catch(FileContentsException e) {
				
				throw new FileContentsException("Invalid file, ",e);
			
			} catch (NullPointerException e) {
				break;
			} catch (IOException e) {
				throw new FileContentsException("Error while reading the file");
			}
			
		}
		if(!listaLabel.casan()) {
			throw new FileContentsException("Invalid file, incorrect format of labels between Bombs and DestroyerAliens");
		}
		
		
		
		
	}
	//MÉTODOS GENERALES
	@Override
	public void receivePoints(int points) {
		this.setPuntos(this.getPuntos() + points);
		
	}
	public boolean isOnBoard(int fila, int columna) {
		return (fila>=0 && fila<NUM_FILAS && columna>=0 && columna<NUM_COLUMNAS);
	}
	
	
	public boolean aliensWin() {
		return !nave.isAlive () || AlienShip.haveLanded();
	}
	
	public boolean playerWin() {
		return AlienShip.allDead();
	}
	
	public void update() {
		listaObjetos.computerAction();
		listaObjetos.update();
		setCiclos(getCiclos() + 1);
	}

	public boolean isFinished() {
		
		return this.playerWin() || this.aliensWin();
	}
	public String getWinnerMessage () {
		if (this.aliensWin()) 
			return "Aliens win!"; 
		else if (this.playerWin()) 
			return "Player wins!"; 
		else return "Player exits the game"; 
	}
	
	//GETTERS Y SETTERS
	public Move getMove() {
		return move;
	}

	public void setMove(Move move) {
		this.move = move;
	}

	public Random getRandom() {
		return rand;
	}

	public Level getLevel() {
		return level;
	}

	public boolean getHayOvni() {
		return hayOvni;
	}

	public void setHayOvni(boolean ovni) {
		this.hayOvni = ovni;
	}

	public GameObjectBoard getListaObjetos() {
		return listaObjetos;
	}

	public void setListaObjetos(GameObjectBoard listaObjetos) {
		this.listaObjetos = listaObjetos;
	}

	
	public int getCiclos() {
		return ciclos;
	}

	public void setCiclos(int ciclos) {
		this.ciclos = ciclos;
	}


	@Override
	public void enableShockWave() {
		this.setShockWave(true);
		
	}
	@Override
	public void enableMissile() {
		this.missile=false;
		
	}
	public BoardInitializer getInitializer() {
		return initializer;
	}
	
	
	public UCMShip getNave() {
		return nave;
	}

	public void setNave(UCMShip nave) {
		this.nave = nave;
	}

	public int getPuntos() {
		return puntos;
	}

	public void setPuntos(int puntos) {
		this.puntos = puntos;
	}

	public boolean getShockWave() {
		return shockWave;
	}

	public void setShockWave(boolean shockWave) {
		this.shockWave = shockWave;
	}


	
	

}
