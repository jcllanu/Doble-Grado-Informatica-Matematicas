package tp.tp1.controller;
import java.util.Scanner;

import tp.tp1.controller.commands.Command;
import tp.tp1.controller.commands.CommandGenerator;
import tp.tp1.game.*;

public class Controller {
	private CommandGenerator commands =  new CommandGenerator();
	private boolean exit;
	private Game game;
	private Scanner scanner;
	private String PROMPT="Introduzca el siguinte comando:";
	private String unknownCommandMsg="Comando incorrecto. ";
	public Controller(Game game,Scanner scanner) {
		this.game = game;
		this.scanner = scanner;
	}
	public void run(){
		exit=false;
		System.out.println(game.data());
		System.out.println(game.toString());
		
		while (!game.isFinished() && !exit){
			System.out.println(PROMPT);
			String[] words = scanner.nextLine().toLowerCase().trim().split ("\\s+");
			Command command=CommandGenerator.parseCommand(words);
			if (command != null) {
				if (command.execute(game, this)) {
					game.update();
					System.out.println(game.data());
					System.out.println(game.toString());
				}
			}
			else {
				System.out.format(unknownCommandMsg);
			}
			
			
		}
		System.out.println(game.getWinnerMessage());
	}
	

	public CommandGenerator getCommands() {
		return commands;
	}

	public void setCommands(CommandGenerator commands) {
		this.commands = commands;
	}

	public boolean isExit() {
		return exit;
	}

	public void setExit(boolean b) {
		this.exit = b;
	}

	public void mostrarPantalla(String texto) {
		System.out.println(texto);
		
	}
	public void setGame(Game game2) {
		this.game=game2;
	}
	
}
