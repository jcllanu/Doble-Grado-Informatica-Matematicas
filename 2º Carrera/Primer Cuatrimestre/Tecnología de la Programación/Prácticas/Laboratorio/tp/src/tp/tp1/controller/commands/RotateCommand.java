package tp.tp1.controller.commands;

import tp.tp1.controller.Controller;
import tp.tp1.exceptions.CommandExecuteException;
import tp.tp1.exceptions.CommandParseException;
import tp.tp1.exceptions.OffWorldException;
import tp.tp1.game.Game;

public class RotateCommand extends Command{

	public static final String CommandText = "rotate";
	public static final String ShortCutText = "rt";
	public static final String CommandTextMsg = "[R]o[t]ate <left|right>";
	public static final String HelpTextMsg = "Rotates the board 90� in th chosen direction";
	private boolean derecha;
	
	public RotateCommand(boolean der){
		super(CommandText, ShortCutText,CommandTextMsg, HelpTextMsg);
		this.derecha=der;
	}	
	
	public RotateCommand() {
		super(CommandText, ShortCutText,CommandTextMsg, HelpTextMsg);
	}

	@Override
	public boolean execute(Game game, Controller controller) throws CommandExecuteException{
		try {
			game.rotate(this.derecha);
		}catch (OffWorldException e) {
			throw new CommandExecuteException("Cannot perform move: ",e);
		}
		return true;
	}
	
	@Override
	public Command parse(String[] s) throws CommandParseException{
		Command command = null;
		
		if(this.matchCommandName(s[0])){
			if(s.length==2) {
				if(s[1].contentEquals("right")||s[1].contentEquals("d")) {
					command = new RotateCommand(true);
				}
				else if(s[1].contentEquals("left")||s[1].contentEquals("i")) {
				
						command = new RotateCommand(false);
				}else {
					throw new CommandParseException(incorrectArgsMsg);
				}
			}else {
				throw new CommandParseException(incorrectNumArgsMsg);
			}
			
		}
		return command;
	}
}
