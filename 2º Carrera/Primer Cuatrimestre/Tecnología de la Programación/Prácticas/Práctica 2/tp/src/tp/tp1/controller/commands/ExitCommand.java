package tp.tp1.controller.commands;

import tp.tp1.controller.Controller;
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
	public boolean execute(Game game, Controller controller) {
		controller.setExit(true);
		return false;
	}
	
	@Override
	public Command parse(String[] s) {
		Command command = null;
		if(this.matchCommandName(s[0])){
			command = new ExitCommand();
		}
		return command;
	}



}
