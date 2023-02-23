package tp.tp1.controller.commands;

import tp.tp1.controller.Controller;
import tp.tp1.exceptions.CommandExecuteException;
import tp.tp1.exceptions.CommandParseException;
import tp.tp1.exceptions.NotEnoughPointsException;
import tp.tp1.game.Game;

public class BuySuperMissileCommand extends Command {

	public static final String CommandText = "buy";
	public static final String ShortCutText = "b";
	public static final String CommandTextMsg = "[B]uy supermissile";
	public static final String HelpTextMsg = "Buy super-missile.";
	
	public BuySuperMissileCommand(){
		super(CommandText, ShortCutText,CommandTextMsg, HelpTextMsg);
	}	

	@Override
	public boolean execute(Game g, Controller c) throws CommandExecuteException{
		try {
			g.buySuperMissile();
		}catch(NotEnoughPointsException e){
			throw new CommandExecuteException("Cannot buy SuperMissile: ",e);
		}
		return true;
	}

	@Override
	public Command parse(String[] s) throws CommandParseException {
		Command command = null;
		if(this.matchCommandName(s[0])){
			command = new BuySuperMissileCommand();
			if(s.length!=1) {
				throw new CommandParseException(incorrectNumArgsMsg);
			}
		}
		return command;
	}

}
