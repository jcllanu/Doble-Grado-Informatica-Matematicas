package tp.tp1.controller.commands;

import tp.tp1.controller.Controller;
import tp.tp1.game.Game;

public class ShockwaveCommand extends Command {

	public static final String CommandText = "shockwave";
	public static final String ShortCutText = "w";
	public static final String CommandTextMsg = "shock[W]ave";
	public static final String HelpTextMsg = "UCM-Ship releases a shock wave.";
	
	public ShockwaveCommand(){
		super(CommandText, ShortCutText,CommandTextMsg, HelpTextMsg);
	}	

	@Override
	public boolean execute(Game game, Controller controller) {//devuelve si se ha podido ejecutar el shockwave
		return game.shockWave();
	}
	
	@Override
	public Command parse(String[] s) {
		Command command = null;
		if(this.matchCommandName(s[0])){
			command = new ShockwaveCommand();
		}
		return command;
	}

	

}
