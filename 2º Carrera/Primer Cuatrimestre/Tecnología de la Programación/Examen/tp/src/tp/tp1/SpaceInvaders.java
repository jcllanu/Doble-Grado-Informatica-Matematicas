package tp.tp1;

import tp.tp1.game.*;
import tp.tp1.controller.*;
import java.util.Random;
import java.util.Scanner;
/*Juan Carlos Llamas y Adrián Sanjuán*/
public class SpaceInvaders {
	

	public static void main(String[] args){
		Game game;
		Controller controller;
		
		Scanner scanner = new Scanner(System.in);
		
		Level level = null;
		Random rand = null;

		
		try {
			args[0] = args[0].toLowerCase();
			level=Level.parse(args[0]);
			if(level==null) {
				throw new IllegalArgumentException();
			}
			rand = new Random(Integer.parseInt(args[1]));
			
		}catch (IndexOutOfBoundsException e1) {
			System.out.println("Usage: Main <EASY|HARD|INSANE> [seed]\r\n");
			System.out.println("Jugarás con nivel EASY.");
			level = Level.EASY;
			rand = new Random(System.currentTimeMillis());
		}catch (NumberFormatException e2) {
			System.out.println("Usage: Main <EASY|HARD|INSANE> [seed]: the seed must be a number");
			rand = new Random(System.currentTimeMillis());
		}catch (IllegalArgumentException e3) {
			System.out.println("Usage: Main <EASY|HARD|INSANE> [seed]: level must be one of: EASY, HARD, INSANE");
			System.out.println("Jugarás con nivel EASY.");
			level = Level.EASY;
			rand = new Random(System.currentTimeMillis());
		}finally {
			game = new Game (level,rand);
			controller = new Controller(game,scanner);
			controller.run();
		}
		
	}


}
