package tp.tp1.game;

import tp.tp1.Level;
import tp.tp1.game.gameObjects.AlienShip;
import tp.tp1.game.gameObjects.BoardInitializer;
import tp.tp1.game.gameObjects.GameObject;
import tp.tp1.game.gameObjects.GamePrinter;
import tp.tp1.game.gameObjects.IPlayerController;
import tp.tp1.game.gameObjects.UCMShip;
import tp.tp1.game.gameObjects.UCMShipLaser;
import tp.tp1.game.gameObjects.UCMShipSuperMisil;
import tp.tp1.game.gameObjects.lists.GameObjectBoard;
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
	private GamePrinter tablero;
	
	
	
	//MÉTODOS DE INICIO DE PARTIDA
	public Game(Level level, Random random){
		this.rand = random;
		this.level = level;
		initializer = new BoardInitializer();
		initGame();
	}
	
	public void initGame() {
		this.move=Move.LEFT;
		this.setCiclos(0);
		this.puntos=0;
		AlienShip.setNumAlien(0);
		UCMShipSuperMisil.setNumSuperMisil(0);
		
		this.listaObjetos= getInitializer().initialize (this, level);
		this.nave = new UCMShip(this, NUM_FILAS-1, UCMShip.COL_INI_UCM, UCMShip.VIDA_UCM);
		this.listaObjetos.add(this.nave);
	}
	
	//MÉTODOS DE PINTADO DE PARTIDA
	public String toString() {
		tablero= new GamePrinter(this,NUM_FILAS,NUM_COLUMNAS);
		return tablero.toString();
		
	}
	
	public String characterAtToString(int i, int j) { //Devuelve el string del personaje en la posición i,j
		return listaObjetos.toString(i, j);
	}

	public String data() {
		String text = new String();
		text = " \nLife: " + nave.getVida() + "\nNumber of cycles: " + getCiclos() + "\nPoints: " +
				puntos +"\nRemaining aliens: "+ AlienShip.getNumAlien();

		if(shockWave){
			text+="\nshockWave: SI";
		}else {
			text+="\nshockWave: NO";
		}
		text+="\nSupermissiles: " + UCMShipSuperMisil.getNumSuperMisil();
		return text;
	}
	
	
	//MÉTODOS LLAMADOS DESDE LOS COMANDOS
	@Override
	public boolean move(int numCells) {/*IGUAL HAY QUE IMPLEMENTAR ESTO EN UCMShip*/
		boolean ok = true;
		if(nave.getCol() + numCells < 0 || nave.getCol() + numCells >=NUM_COLUMNAS) {
			ok =false;
		}else {
			nave.setCol(nave.getCol() + numCells);
		}
		return ok;
	}


	@Override
	public boolean shockWave() {
		boolean hayShockwave=this.shockWave;
		
		if(hayShockwave) {
			this.listaObjetos.shockWaveAttack();
			this.shockWave=false;
		}
		return hayShockwave;
	}
	
	@Override
	public boolean shootLaser(boolean supermisil) {
		boolean hayLaser=this.missile, haySupermisiles=true;
		GameObject mis;
		if(!hayLaser) {
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
					haySupermisiles=false;
				}
			}
		}
		return !hayLaser && haySupermisiles;
	}
	
	public boolean buySuperMissile() {
		boolean possible = false;
		if (this.puntos >= 20) {
			this.puntos-=20;
			UCMShipSuperMisil.setNumSuperMisil(UCMShipSuperMisil.getNumSuperMisil() + 1);
			possible = true;
		}
		return possible ;
	}
	
	
	//MÉTODOS GENERALES
	@Override
	public void receivePoints(int points) {
		this.puntos+=points;
		
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
		this.shockWave=true;
		
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

}
