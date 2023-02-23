package tp.tp1.controller.commands;

import tp.tp1.controller.Controller;
import tp.tp1.exceptions.CommandExecuteException;
import tp.tp1.exceptions.CommandParseException;
import tp.tp1.game.Game;

public class ExitCommand extends Command {
	public static final String CommandText = "exit";
	public static final String ShortCutText = "e";
	public static final String CommandTextMsg = "[E]xit";
	public static final String HelpTextMsg = "Terminate the program.";
	
	
	public ExitCommand(){
		super(CommandText, ShortCutText,CommandTextMsg, HelpTextMsg);
	}	

	@Override
	public boolean execute(Game game, Controller controller) throws CommandExecuteException {
		Command command = new SaveCommand("exit");
		command.execute(game, controller);
		controller.setExit(true);
		return false;
	}
	
	@Override
	public Command parse(String[] s) throws CommandParseException {
		Command command = null;
		if(this.matchCommandName(s[0])){
			command = new ExitCommand();
			if(s.length!=1) {
				throw new CommandParseException(incorrectNumArgsMsg);
			}
		}
		
		return command;
	}


}
