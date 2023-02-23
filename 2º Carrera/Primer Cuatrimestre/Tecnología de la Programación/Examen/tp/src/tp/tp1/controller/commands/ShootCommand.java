package tp.tp1.controller.commands;

import tp.tp1.controller.Controller;
import tp.tp1.exceptions.CommandExecuteException;
import tp.tp1.exceptions.CommandParseException;
import tp.tp1.exceptions.MissileInFlightException;
import tp.tp1.exceptions.NoAvailableSupermissileException;
import tp.tp1.game.Game;

public class ShootCommand extends Command {

	public static final String CommandText = "shoot";
	public static final String ShortCutText = "s";
	public static final String CommandTextMsg = "[S]hoot ([S]upermissile)";
	public static final String HelpTextMsg = " UCM-Ship launches a missile (or a supermissile if in possesion).";
	
	private boolean supermisil;
	
	public ShootCommand(){ 
		super(CommandText, ShortCutText,CommandTextMsg, HelpTextMsg);

	}
	public ShootCommand(boolean supermisil){ 
		super(CommandText, ShortCutText,CommandTextMsg, HelpTextMsg);
		this.supermisil = supermisil;
	}	

	@Override
	public boolean execute(Game game, Controller controller) throws CommandExecuteException{
		try {
			game.shootLaser(this.supermisil);
		} catch(MissileInFlightException | NoAvailableSupermissileException e) {
			throw new CommandExecuteException("Cannot fire missile: ",e);
		}
		return true;
	}
	
	@Override
	public Command parse(String[] s) throws CommandParseException{ 
		Command command = null;
		
		if(this.matchCommandName(s[0])){
			if(s.length > 2) {
				throw new CommandParseException(incorrectNumArgsMsg);
			}else {
				if(s.length > 1) {
					if(s[1].contentEquals("supermissile")||s[1].contentEquals("s")) {
						command = new ShootCommand(true);
						
					}else {
						throw new CommandParseException(incorrectArgsMsg);
					}
				}else {
					command = new ShootCommand(false);
				}
			}
		}
		
		return command;
	}

	public boolean isSupermisil() {
		return supermisil;
	}

	public void setSupermisil(boolean supermisil) {
		this.supermisil = supermisil;
	}

	

}
