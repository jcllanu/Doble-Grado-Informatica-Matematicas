package tp.tp1;

import tp.tp1.game.*;
import tp.tp1.controller.*;
import tp.tp1.util.*;

import java.util.Random;
import java.util.Scanner;

public class SpaceInvaders {
	public static void main(String[] args) {
		Game game;
		Controller controller;
		
		Scanner scanner = new Scanner(System.in);
		
		Level level = null;
		Random rand;
		
		if(args.length>0) {
			args[0] = args[0].toLowerCase();
			if(args[0].equals("easy")) {
				level = Level.EASY;
			}else if(args[0].equals("hard")) {
				level = Level.HARD;
			}else if(args[0].equals("insane")) {
				level = Level.INSANE;
			}else {
				System.out.println("Nivel incorrecto. Jugarás con nivel EASY.");
				level = Level.EASY;
			}
		}else {	
			level = Level.EASY;
		}
		if(args.length>1) {
			rand = new Random(Integer.parseInt(args[1]));
		}else {
			rand = new Random(System.currentTimeMillis());
		}

		game = new Game (level,rand);
		controller = new Controller(game,scanner);
		controller.run();
		
	}


}
