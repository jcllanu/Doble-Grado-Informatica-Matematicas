package tp.tp1.controller.commands;

import tp.tp1.controller.Controller;
import tp.tp1.exceptions.CommandParseException;
import tp.tp1.game.Game;
import tp.tp1.game.Mode;

public class NoneCommand extends Command{
	public static final String CommandText = "none";
	public static final String ShortCutText = "n";
	public static final String CommandTextMsg = "[N]one";
	public static final String HelpTextMsg = "Skips one cycle.";
	
	public NoneCommand(){
		super(CommandText, ShortCutText,CommandTextMsg, HelpTextMsg);
	}	

	@Override
	public boolean execute(Game game, Controller controller) {
		if(game.getNave().getHyperspace()==Mode.WARM_UP) {
			game.getNave().setHyperspace(Mode.ON);
		}
		return true;
	}
	
	@Override
	public Command parse(String[] s) throws CommandParseException {
		Command command = null;
	
		if(this.matchCommandName(s[0])){
			command = new NoneCommand();
			if(s.length!=1) {
				throw new CommandParseException(incorrectNumArgsMsg);
			}
		}
		
		return command;
	}

}
