package tp.tp1.controller;
import java.util.Scanner;

import tp.tp1.controller.commands.Command;
import tp.tp1.controller.commands.CommandGenerator;
import tp.tp1.exceptions.CommandExecuteException;
import tp.tp1.exceptions.CommandParseException;
import tp.tp1.game.*;
import tp.tp1.view.GamePrinter;
import tp.tp1.view.PrinterTypes;


public class Controller {
	private CommandGenerator commands =  new CommandGenerator();
	private boolean exit;
	private Game game;
	private Scanner scanner;
	private String PROMPT="Command: ";
	private String unknownCommandMsg = "Unknown command. ";
	private GamePrinter printer=PrinterTypes.BOARDPRINTER.getObject();
	
	
	
	public Controller(Game game,Scanner scanner) {
		this.game = game;
		this.scanner = scanner;
		this.printer.setGame(game);
	}
	public void run(){
		exit=false;
		System.out.println(game.data());
		System.out.println(getPrinter());
		
		while (!game.isFinished() && !exit){
			System.out.println(PROMPT);
			String[] words = scanner.nextLine().toLowerCase().trim().split ("\\s+");
			try {
				Command command=CommandGenerator.parseCommand(words);
				if (command != null) {
					if(command.execute(game, this)) {
					game.update();
					System.out.println(game.data());
					this.printer.setGame(game);
					System.out.println(getPrinter());
	
					}
				}
				else {
					System.out.format(unknownCommandMsg);
				}
			}catch(CommandParseException | CommandExecuteException ex) {
				System.out.format(ex.getMessage() + " %n %n");
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
	public GamePrinter getPrinter() {
		return printer;
	}
	public void setPrinter(GamePrinter printer) {
		this.printer = printer;
	}
	
}
