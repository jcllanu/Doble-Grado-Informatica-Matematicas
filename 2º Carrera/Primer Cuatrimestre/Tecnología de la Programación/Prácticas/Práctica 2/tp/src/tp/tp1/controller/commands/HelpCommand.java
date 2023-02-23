package tp.tp1.controller.commands;

import tp.tp1.controller.Controller;
import tp.tp1.game.Game;

public class HelpCommand extends Command {
	public static final String CommandText = "help";
	public static final String ShortCutText = "h";
	public static final String CommandTextMsg = "[H]elp";
	public static final String HelpTextMsg = "Prints this help message.";
	
	public HelpCommand(){
		super(CommandText, ShortCutText,CommandTextMsg, HelpTextMsg);
	}	

	@Override
	public boolean execute(Game game, Controller controller) {
		controller.mostrarPantalla(CommandGenerator.commandHelp());
		return false;
	}
	
	@Override
	public Command parse(String[] s) {
		Command command = null;
		if(this.matchCommandName(s[0])){
			command = new HelpCommand();
		}
		return command;
	}

	
	
}
