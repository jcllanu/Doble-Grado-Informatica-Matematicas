package tp.tp1.controller.commands;

import tp.tp1.controller.Controller;
import tp.tp1.exceptions.CommandExecuteException;
import tp.tp1.exceptions.CommandParseException;
import tp.tp1.exceptions.HyperspaceException;
import tp.tp1.exceptions.NoShockwaveException;
import tp.tp1.game.Game;

public class HyperspaceCommand extends Command{

	public static final String CommandText = "hyperspace";
	public static final String ShortCutText = "hyperspace";
	public static final String CommandTextMsg = "[Hyperspace]";
	public static final String HelpTextMsg = "Enables the hyperspace jump.";
	
	public HyperspaceCommand(){
		super(CommandText, ShortCutText,CommandTextMsg, HelpTextMsg);
	}	

	@Override
	public boolean execute(Game game, Controller controller) throws CommandExecuteException{
		try {
			game.hyperspace();
		}catch (HyperspaceException e) {
			throw new CommandExecuteException("Cannot enable hyperspace: ", e);
		}
		return true;
	}
	
	@Override
	public Command parse(String[] s) throws CommandParseException {
		Command command = null;
		if(this.matchCommandName(s[0])){
			command = new HyperspaceCommand();
			if(s.length!=1) {
				throw new CommandParseException(incorrectNumArgsMsg);
			}
		}
		return command;
	}
	

}
