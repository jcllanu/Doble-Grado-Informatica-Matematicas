package tp.tp1.controller.commands;

import tp.tp1.controller.Controller;
import tp.tp1.game.Game;

public class ShootCommand extends Command {

	public static final String CommandText = "shoot";
	public static final String ShortCutText = "s";
	//public static final String CommandText2 = "shoot supermissile";
	//public static final String ShortCutText2 = "s s";
	public static final String CommandTextMsg = "[S]hoot ([S]upermissile)";
	public static final String HelpTextMsg = " UCM-Ship launches a missile (or a supermissile if in possesion).";
	
	private boolean supermisil;
	
	public ShootCommand(){ //dos constructores inspirandome en el move
		super(CommandText, ShortCutText,CommandTextMsg, HelpTextMsg);

	}
	public ShootCommand(boolean supermisil){ 
		super(CommandText, ShortCutText,CommandTextMsg, HelpTextMsg);
		this.supermisil = supermisil;
	}	

	@Override
	public boolean execute(Game game, Controller controller) {//devuelve si se ha podido ejecutar el shoot
		return game.shootLaser(this.supermisil);
	}
	
	@Override
	public Command parse(String[] s) { 
		Command command = null;
		if(this.matchCommandName(s[0])){
			if(s.length > 1) {
				if(s[1].contentEquals("supermissile")||s[1].contentEquals("s")) {
					command = new ShootCommand(true);
					
				}
			}else {
				command = new ShootCommand(false);
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
