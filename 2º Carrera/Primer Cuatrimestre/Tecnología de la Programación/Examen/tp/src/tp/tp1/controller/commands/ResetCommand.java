package tp.tp1.controller.commands;

import java.util.Random;

import tp.tp1.Level;
import tp.tp1.controller.Controller;
import tp.tp1.exceptions.CommandParseException;
import tp.tp1.game.Game;

public class ResetCommand extends Command {

	public static final String CommandText = "reset";
	public static final String ShortCutText = "r";
	public static final String CommandTextMsg = "[R]eset";
	public static final String HelpTextMsg = "Starts a new game.";
	
	public ResetCommand(){
		super(CommandText, ShortCutText,CommandTextMsg, HelpTextMsg);
	}	

	@Override
	public boolean execute(Game game, Controller controller) {
		Level aux1=game.getLevel();
		Random aux2=game.getRandom();
		game=null;
		game=new Game(aux1,aux2);
		controller.setGame(game);
		controller.mostrarPantalla(game.data());
		controller.getPrinter().setGame(game);
		controller.mostrarPantalla(controller.getPrinter().toString());
		return false;
	}
	
	@Override
	public Command parse(String[] s) throws CommandParseException {
		Command command = null;
		if(this.matchCommandName(s[0])){
			command = new ResetCommand();
			if(s.length!=1) {
				throw new CommandParseException(incorrectNumArgsMsg);
			}
		}
		return command;
	}

}
