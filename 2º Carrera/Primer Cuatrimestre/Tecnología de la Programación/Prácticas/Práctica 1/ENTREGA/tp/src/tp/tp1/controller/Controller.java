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