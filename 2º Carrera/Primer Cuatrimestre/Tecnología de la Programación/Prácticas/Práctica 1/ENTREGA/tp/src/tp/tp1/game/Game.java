package tp.tp1.game;

import tp.tp1.Level;
import tp.tp1.game.characters.*;

import java.util.Random;
import java.util.Scanner;
import tp.tp1.*;


public class Game {
	
	public final static int NUM_FILAS = 8;
	public final static int NUM_COLUMNAS = 9;
	private Level level;
	private Random rand;
	private Move move;
	private int ciclos;
	private int puntos;
	private boolean shockWave;
	
	private BombList listaBombas, recienDisparadas;
	private DestroyerAlienList listaDestroyers;
	private RegularAlienList listaRegulars;
	private	Ovni ovni;
	private	UCMShip nave;
	private UCMShipLaser laser;
	private GamePrinter tablero;
	

	

	public Game(Level level, Random seed) {

		this.level=level;
		this.rand=seed;
	}
	
	public void initGame() { //inicializa el juego
		nave = new UCMShip();
		ovni = null;
		laser=null;
		listaDestroyers = new DestroyerAlienList(level);
		listaRegulars = new RegularAlienList(level);
		listaBombas = new BombList(); 
		recienDisparadas = new BombList();
		move = Move.LEFT;
		ciclos = 0;
		puntos = 0;
		shockWave=false;
	}
	
	
	
	public boolean userCommand(Scanner scanner) { //parsea el comando y ejecuta la acción
		String comando, com1, com2;
		boolean exit=false;
		boolean repComando=true;
		
		System.out.print("");
		System.out.print("Comando: ");
		comando = scanner.next();
		comando=comando.toLowerCase();
		while(repComando) {
			repComando=false;
			if(comando.contentEquals("move")||comando.contentEquals("m")) {
				com1 = scanner.next();
				com1=com1.toLowerCase();
				com2 = scanner.next();
				com2=com2.toLowerCase();
				
				if(com1.contentEquals("right")||com1.contentEquals("d")) {
					if(com2.contentEquals("1") && this.getNave().getCol()+1 < Game.NUM_COLUMNAS) {
						this.getNave().movimiento(Move.RIGHT, 1);
						
					}else if (com2.contentEquals("2") && this.getNave().getCol()+2 < Game.NUM_COLUMNAS){
						this.getNave().movimiento(Move.RIGHT, 2);
					
					}else {
						System.out.println("Movimiento no válido");
						repComando=true;
					}	
				
				}else if(com1.contentEquals("left")||com1.contentEquals("i")){
					if(com2.contentEquals("1") && this.getNave().getCol()-1 >= 0) {
						this.getNave().movimiento(Move.LEFT, 1);
					}else if (com2.contentEquals("2") && this.getNave().getCol()-2 >= 0){
						this.getNave().movimiento(Move.LEFT, 2);
					}else {
						System.out.println("Movimiento no válido");
						repComando=true;
					}
				}else {
					System.out.println("Movimiento no válido");
					repComando=true;
				}
			}else if(comando.contentEquals("shoot")||comando.contentEquals("s")) {
				repComando=!this.shoot();
				if(repComando) {
					System.out.println("No puedes disparar");
				}
				
			}else if(comando.contentEquals("shockwave")||comando.contentEquals("w")) {
				repComando=!this.shockwave();
				if(repComando) {
					System.out.println("");
					System.out.println("No puedes ejecutar shockwave");
				}
				
			}else if(comando.contentEquals("none")||comando.contentEquals("n")||comando.contentEquals("")) {
				
			}else if(comando.contentEquals("list")||comando.contentEquals("l")) {
				this.mostrarLista();
				repComando=true;
				
			}else if(comando.contentEquals("reset")||comando.contentEquals("r")) {
				this.initGame();
				repComando=true;
				System.out.print(this.toString());
				
			}else if(comando.contentEquals("help")||comando.contentEquals("h")) {
				this.help();
				repComando=true;
			
			}else if(comando.contentEquals("exit")||comando.contentEquals("e")) {
				System.out.println("");
				System.out.println("                            GAME OVER");
				exit=true;
				
			}else {
				repComando=true;
			}
			if(repComando) {
				System.out.print("Comando: ");
				comando = scanner.next();
				comando.toLowerCase();
			}
		}
		return exit;
	}
	
	
	private boolean shoot() {
		boolean yaDisparado=this.nave.getDisparo();
		if(!yaDisparado) {
			laser=new UCMShipLaser(this.getNave().getCol());
			this.getNave().setDisparo(true);
		}
		return !yaDisparado;
	}
	
	private boolean shockwave() {
		boolean hayShockwave=this.shockWave;
		
		if(hayShockwave) {
			puntos+=listaDestroyers.shockWave();	
			puntos+=listaRegulars.shockWave();
			this.shockWave=false;
		}
		return hayShockwave;
	}
	private void mostrarLista() {
		System.out.println("");
		System.out.println("[R]egular ship: Points: "+RegularAlien.PUNTOS_REGULAR +" - Harm: "+ 0+" - Shield: "+RegularAlien.VIDA_REGULAR);
		System.out.println("[D]estroyer ship: Points: "+ DestroyerAlien.PUNTOS_DESTROYER+" - Harm: "+ Bomb.DANNO_BOMB+" - Shield: "+DestroyerAlien.VIDA_DESTROYER);
		System.out.println("[O]vni: Points: "+ Ovni.PUNTOS_OVNI+" - Harm: "+ 0 +" - Shield: "+Ovni.VIDA_OVNI);
		System.out.println(nave.toString()+": Harm: "+UCMShipLaser.DANNO_LASER+" - Shield: "+ UCMShip.VIDA_UCM);
	}	
	private void help() {
		System.out.println("");
		System.out.println("move <left|right><1|2>: Moves UCM-Ship to the indicated direction.");
		System.out.println("shoot: UCM-Ship launches a missile.");
		System.out.println("shockWave: UCM-Ship releases a shock wave.");
		System.out.println("list: Prints the list of available ships.");
		System.out.println("reset: Starts a new game.");
		System.out.println("help: Prints this help message.");
		System.out.println("exit: Terminates the program.");
		System.out.println("[none]: Skips one cycle.");
	}
	
	
	public void computerAction() { //Lanza bonmbas y genera ovnis con cierta probabilidad
		int aleatorio;
		
		this.recienDisparadas.setContador(0);
		listaDestroyers.dispara(rand, level, listaBombas, recienDisparadas);
		
		aleatorio=rand.nextInt(10);
		if(this.ovni==null && aleatorio < level.getFrecuenciaOvni()*10) {
			this.ovni= new Ovni();
		}
		
	}
	
	public boolean update() { 
		this.movimientoLaser();
		this.movimientoBombas();
		/*this.movimientoAliensA();*/
		this.movimientoAliensB();
		this.movimientoOvni();
		
		ciclos++;
		
		return this.finPartida();
	}
	

	private boolean finPartida() { //Devuelve true en caso de que finalice la partida (bien gane el jugador o los aliens)
		boolean end = false;
	
		
		
		if (this.listaDestroyers.getContador() == 0 && this.listaRegulars.getContador() == 0) {
			end = true;
			System.out.println("                            ¡¡¡Player wins!!!");
			
		}
		else {
			if(listaDestroyers.llegaAbajo()) {
				end=true;
				System.out.println("                            ¡¡¡Aliens win!!!");
			}
			if(!end && listaRegulars.llegaAbajo()) {
				end = true;
				System.out.println("                            ¡¡¡Aliens win!!!");
			}
			
			if(!end && this.nave.getResistencia() <= 0) {
				end = true;
				System.out.println("                            ¡¡¡Aliens win!!!");
			}
		}
		
		return end;
	}

	
	private void movimientoLaser() {
		if(laser!=null) {
			laser.movimiento();
			if(laser.getFil() < 0) {
				laser=null;
				nave.setDisparo(false);
			}
			this.revisarImpactosLaser();
		}
	}
	
	private void movimientoBombas() {
		listaBombas.movimiento();
		
		if(laser!=null && listaBombas.impactaLaser(laser)) {
			laser=null;
			nave.setDisparo(false);
		}
		if(listaBombas.impactaNave(nave)) {
			nave.setResistencia(nave.getResistencia()-Bomb.DANNO_BOMB);
		}
		listaBombas.comprobarMargenes();
	}
	
	private void movimientoAliensA() {
		int minimo = 0,maximo = 0;
		int maximoReg=listaRegulars.maximaColumna();
		int minimoReg=listaRegulars.minimaColumna();
		int maximoDes=listaDestroyers.maximaColumna();
		int minimoDes=listaDestroyers.minimaColumna();
		
		if(maximoDes>maximoReg) {
			maximo=maximoDes;
		}else {
			maximo=maximoReg;
		}
		if(minimoDes<minimoReg) {
			minimo=minimoDes;
		}else {
			minimo=minimoReg;
		}
		
		if (ciclos % level.getVelocidad() == 0) {
			if(move == Move.LEFT) {
				if(minimo != 0) {
					listaRegulars.movimiento(Move.LEFT);
					listaDestroyers.movimiento(Move.LEFT);
					
				}else {
					listaRegulars.movimiento(Move.DOWN);
					listaDestroyers.movimiento(Move.DOWN);
					recienDisparadas.movimiento();
					
					if(laser!=null && listaBombas.impactaLaser(laser) ) {
						laser = null;
						nave.setDisparo(false);
					}
					move = Move.RIGHT;
				}
			}else{
				if(maximo != NUM_COLUMNAS-1) {
					listaRegulars.movimiento(Move.RIGHT);
					listaDestroyers.movimiento(Move.RIGHT);
					
					
				}else {
					listaRegulars.movimiento(Move.DOWN);
					listaDestroyers.movimiento(Move.DOWN);
					recienDisparadas.movimiento();
					
					if(laser!=null && listaBombas.impactaLaser(laser) ) {
						laser = null;
						nave.setDisparo(false);
					}
					move = Move.LEFT;
				}
			}
		}
		if(laser!= null) {
			int punt1=listaRegulars.impactaLaser(laser);
			if(punt1>=0) {
				laser = null;
				nave.setDisparo(false);
				puntos+=punt1;
			}
		}	
		if(laser!= null) {
			int punt2=listaDestroyers.impactaLaser(laser);
			if(punt2>=0) {
				laser = null;
				nave.setDisparo(false);
				puntos+=punt2;
			}
		}
		
	}
	private void movimientoAliensB() {
		int minimo = 0,maximo = 0;
		int maximoReg=listaRegulars.maximaColumna();
		int minimoReg=listaRegulars.minimaColumna();
		int maximoDes=listaDestroyers.maximaColumna();
		int minimoDes=listaDestroyers.minimaColumna();
		
		if(maximoDes > maximoReg) {
			maximo = maximoDes;
		}else {
			maximo = maximoReg;
		}
		if(minimoDes < minimoReg) {
			minimo = minimoDes;
		}else {
			minimo = minimoReg;
		}
		
		if(minimo == 0 && move == Move.LEFT) {
			listaRegulars.movimiento(Move.DOWN);
			listaDestroyers.movimiento(Move.DOWN);
			recienDisparadas.movimiento();
			
			if(laser!= null && listaBombas.impactaLaser(laser) ) {
				laser = null;
				nave.setDisparo(false);
			}
			move = Move.RIGHT;
			
		}else if(maximo==NUM_COLUMNAS-1 && move == Move.RIGHT) {
			listaRegulars.movimiento(Move.DOWN);
			listaDestroyers.movimiento(Move.DOWN);
			recienDisparadas.movimiento();
			
			if(laser!=null && listaBombas.impactaLaser(laser) ) {
				laser = null;
				nave.setDisparo(false);
			}
			move = Move.LEFT;
			
		}else if (ciclos % level.getVelocidad() == 0) {
			if(move == Move.LEFT) {
				listaRegulars.movimiento(Move.LEFT);
				listaDestroyers.movimiento(Move.LEFT);
			}
			else {
				listaRegulars.movimiento(Move.RIGHT);
				listaDestroyers.movimiento(Move.RIGHT);
			}
		}
		
		
		if(laser!= null) {
			int punt1=listaRegulars.impactaLaser(laser);
			if(punt1>=0) {
				laser = null;
				nave.setDisparo(false);
				puntos+=punt1;
			}
		}	
		if(laser!= null) {
			int punt2=listaDestroyers.impactaLaser(laser);
			if(punt2>=0) {
				laser = null;
				nave.setDisparo(false);
				puntos+=punt2;
			}
		}
		
	}
	
	
	private void movimientoOvni() {
		if (ovni != null) {
			ovni.movimiento();
			if(ovni.getCol()<0) {
				ovni = null;
			}
		}
		
		if (laser!=null && ovni != null) {
			if(laser.getCol() == ovni.getCol() && laser.getFil() == ovni.getFil()) {
				puntos+=ovni.getPuntos();
				laser = null;
				ovni= null;
				shockWave = true;
				nave.setDisparo(false);
			}
		}
		
	}
	
	private void revisarImpactosLaser() {
		boolean impacto=false;
		
		if(laser!=null && listaBombas.impactaLaser(laser) ) {
			impacto=true;
		}
		if(laser!=null) {
			int punt1 = listaRegulars.impactaLaser(laser);
			if(punt1>=0) {
				impacto=true;
				puntos+=punt1;
			}
			
		}
		if(laser!=null) {
			int punt2 = listaDestroyers.impactaLaser(laser);
			if(punt2>=0) {
				impacto=true;
				puntos+=punt2;
			}
		}
		if(impacto) {
			laser = null;
			nave.setDisparo(false);
		}
		
		
		if (ovni != null && laser!=null && laser.getCol() == ovni.getCol() && laser.getFil() == ovni.getFil()) {
			puntos+=ovni.getPuntos();
			laser = null;
			ovni= null;
			shockWave = true;
			nave.setDisparo(false);
			
	
		}
		
	}
	
	
	

	public String characterAtToString(int i, int j) { //Devuelve el string del personaje en la posición i,j
		boolean encontrado = false;
		String devuelve="";
		
		if(this.ovni!=null && this.ovni.getFil()==i && this.ovni.getCol()==j) {
			devuelve=this.ovni.toString();
			
		}else if(this.nave!=null && this.nave.getFil()==i && this.nave.getCol()==j) {
			devuelve=this.nave.toString();
			
		}else if(this.laser!=null && this.laser.getFil()==i && this.laser.getCol()==j) {
			devuelve=this.laser.toString();
			
		}else {
			
			if(this.listaBombas!=null) {
				devuelve=listaBombas.characterAtToString(i, j);
				if(!devuelve.equals("")) {
					encontrado=true;
				}
			}
		
			if(this.listaDestroyers!=null && !encontrado) {
				devuelve=listaDestroyers.characterAtToString(i, j);
				if(!devuelve.equals("")) {
					encontrado=true;
				}
			}
			
			if(this.listaRegulars!=null && !encontrado) {
				devuelve=listaRegulars.characterAtToString(i, j);
				
			}
		}
		return devuelve;
	}

	
	public String toString() {
		tablero= new GamePrinter(this,NUM_FILAS,NUM_COLUMNAS);
		return tablero.toString();
		
	}
	

	public UCMShip getNave() {
		return nave;
	}

	public void setNave(UCMShip nave) {
		this.nave = nave;
	}

	public void data() {
		System.out.println("");
		System.out.println("Life: "+nave.getResistencia());
		System.out.println("Number of cycles: " + ciclos);
		System.out.println("Points: " + puntos);
		System.out.println("Remaining aliens: "+(listaRegulars.getContador()+listaDestroyers.getContador()));
		if(shockWave) {
			System.out.println("shockWave: SI" );
		}else {
			System.out.println("shockWave: NO" );
		}
		
	}
}
