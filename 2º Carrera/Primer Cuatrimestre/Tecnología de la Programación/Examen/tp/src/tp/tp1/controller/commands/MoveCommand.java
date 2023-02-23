package tp.tp1.controller.commands;

import tp.tp1.controller.Controller;
import tp.tp1.exceptions.CommandExecuteException;
import tp.tp1.exceptions.CommandParseException;
import tp.tp1.exceptions.HyperspaceException;
import tp.tp1.exceptions.OffWorldException;
import tp.tp1.exceptions.WarmUpEngineException;
import tp.tp1.game.Game;


public class MoveCommand extends Command {

	public static final String CommandText = "move";
	public static final String ShortCutText = "m";
	public static final String CommandTextMsg = "[M]ove <left|right><1|2>";
	public static final String HelpTextMsg = "Moves UCM-Ship to the indicated direction.";
	private int desplazamiento;

	
	public MoveCommand(){
		super(CommandText, ShortCutText,CommandTextMsg, HelpTextMsg);
		
	}	
	public MoveCommand(int despl){
		super(CommandText, ShortCutText,CommandTextMsg, HelpTextMsg);
		this.desplazamiento=despl;
	}	

	@Override
	public boolean execute(Game game, Controller controller) throws CommandExecuteException{
		
		try {
			game.move(this.desplazamiento);
		}catch (OffWorldException | HyperspaceException e) {
			throw new CommandExecuteException("Cannot perform move: ",e);
		}catch (WarmUpEngineException e) {
			System.out.format(e.getMessage() + " %n %n");
		}
		return true;
	}
	
	@Override
	public Command parse(String[] s) throws CommandParseException{
		Command command = null;
		
		if(this.matchCommandName(s[0])){
			if(s.length==3) {
				if(s[1].contentEquals("right")||s[1].contentEquals("d")||s[1].contentEquals("left")||s[1].contentEquals("i")) {
					try {
						command = new MoveCommand(Integer.parseInt(s[2])*direccion(s[1]));
					}catch(Exception e) {
						throw new CommandParseException(incorrectArgsMsg);
					}
					
				}else {
					throw new CommandParseException(incorrectArgsMsg);
				}
			}else {
				throw new CommandParseException(incorrectNumArgsMsg);
			}
			
		}
		return command;
	}
	private int direccion(String string) {
		int dir =-1;
		if(string.contentEquals("right")||string.contentEquals("d")) {
			dir = 1;
		}
		return dir;
	}

	
}
