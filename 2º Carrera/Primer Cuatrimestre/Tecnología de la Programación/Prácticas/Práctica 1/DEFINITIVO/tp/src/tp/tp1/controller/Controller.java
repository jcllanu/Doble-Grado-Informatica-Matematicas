package tp.tp1.controller;
import java.util.Scanner;

import tp.tp1.game.*;
import tp.tp1.game.characters.UCMShip;
import tp.tp1.util.*;

public class Controller {
	private Game game;
	private Scanner scanner;
	
	public Controller(Game game,Scanner scanner) {
		this.game = game;
		this.scanner = scanner;
	}
	public void run(){
		boolean fin=false;
		this.game.initGame();
		this.game.data();
		System.out.print(this.game.toString());
		while(!fin && !this.game.userCommand(this.scanner)) {
			this.game.computerAction();
			fin = this.game.update();
			this.game.data();
			System.out.print(this.game.toString());
		}
		
	}
}
		/*
		while (!fin) {
			System.out.print(this.game.toString());
			System.out.print("Comando: ");
			comando = this.scanner.next();
			comando.toLowerCase();

			if(comando.contentEquals("move")||comando.contentEquals("m")) {
				com1 = this.scanner.next();
				com1.toLowerCase();
				com2 = this.scanner.next();
				com2.toLowerCase();
				
				if(com1.contentEquals("right")) {
					if(com2.contentEquals("1") && game.getNave().getCol()+1 < Game.NUM_COLUMNAS) {
						game.getNave().movimiento(Move.RIGHT, 1);
						
					}else if (com2.contentEquals("2") && game.getNave().getCol()+2 < Game.NUM_COLUMNAS){
						game.getNave().movimiento(Move.RIGHT, 2);
						
					}else {
						System.out.println("Movimiento no válido");
					}
					
				}else if(com1.contentEquals("left")){
					if(com2.contentEquals("1") && game.getNave().getCol()-1 >= 0) {
						game.getNave().movimiento(Move.LEFT, 1);
					}else if (com2.contentEquals("2") && game.getNave().getCol()-2 >= 0){
						game.getNave().movimiento(Move.LEFT, 2);
					}else {
						System.out.println("Movimiento no válido");
					}
				}else {
					System.out.println("Movimiento no válido");
				}
			}else if(comando.contentEquals("shoot")||comando.contentEquals("s")) {
				game.shoot();
			}else if(comando.contentEquals("shockwave")||comando.contentEquals("w")) {
				game.shockwave();
			}else if(comando.contentEquals("none")||comando.contentEquals("n")||comando.contentEquals("")) {
				
			}else if(comando.contentEquals("list")||comando.contentEquals("l")) {
				game.mostrarLista();
			}else if(comando.contentEquals("reset")||comando.contentEquals("r")) {
				game.initGame();
			}else if(comando.contentEquals("help")||comando.contentEquals("h")) {
				this.help();
			}else if(comando.contentEquals("exit")||comando.contentEquals("e")) {
				fin=true;
				System.out.println("GAME OVER");
			}
		}
	}
	private void help() {
		System.out.println("move <left|right><1|2>: Moves UCM-Ship to the indicated direction.");
		System.out.println("shoot: UCM-Ship launches a missile.");
		System.out.println("shockWave: UCM-Ship releases a shock wave.");
		System.out.println("list: Prints the list of available ships.");
		System.out.println("reset: Starts a new game.");
		System.out.println("help: Prints this help message.");
		System.out.println("exit: Terminates the program.");
		System.out.println("[none]: Skips one cycle.");
	}
	
}
*/