package tp.tp1.controller.commands;

import tp.tp1.controller.Controller;
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
	public boolean execute(Game g, Controller c) {
		
		return g.buySuperMissile();
	}

	@Override
	public Command parse(String[] s) {
		Command command = null;
		if(this.matchCommandName(s[0])){
			command = new BuySuperMissileCommand();
		}
		return command;
	}

}
