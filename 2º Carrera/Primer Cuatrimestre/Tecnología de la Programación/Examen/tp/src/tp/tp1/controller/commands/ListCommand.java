package tp.tp1.controller.commands;

import tp.tp1.controller.Controller;
import tp.tp1.exceptions.CommandParseException;
import tp.tp1.game.Game;
import tp.tp1.game.gameObjects.Bomb;
import tp.tp1.game.gameObjects.DestroyerAlien;
import tp.tp1.game.gameObjects.ExplosiveAlien;
import tp.tp1.game.gameObjects.Ovni;
import tp.tp1.game.gameObjects.RegularAlien;
import tp.tp1.game.gameObjects.UCMShip;
import tp.tp1.game.gameObjects.UCMShipLaser;
import tp.tp1.game.gameObjects.UCMShipSuperMisil;

public class ListCommand extends Command {
	public static final String CommandText = "list";
	public static final String ShortCutText = "l";
	public static final String CommandTextMsg = "[L]ist";
	public static final String HelpTextMsg = "Prints the list of available ships.";
	
	public ListCommand(){
		super(CommandText, ShortCutText,CommandTextMsg, HelpTextMsg);
	}	

	@Override
	public boolean execute(Game game, Controller controller) {
		controller.mostrarPantalla(this.mostrarLista(game));
		return false;
		
	}
	private String mostrarLista(Game game) {
		String dev ="[R]egular ship: Points: "+RegularAlien.PUNTOS_REGULAR +" - Harm: "+ 0+" - Shield: "+RegularAlien.VIDA_REGULAR+"\n"+
				"[E]xplosive ship: Points: "+ExplosiveAlien.PUNTOS_EXPLOSIVE +" - Harm: "+ExplosiveAlien.DANNO_EXPLOSIVE+" - Shield: "+ExplosiveAlien.VIDA_EXPLOSIVE+"\n"+
				"[D]estroyer ship: Points: "+ DestroyerAlien.PUNTOS_DESTROYER+" - Harm: "+ Bomb.DANNO_BOMBA+" - Shield: "+
				DestroyerAlien.VIDA_DESTROYER+"\n"+"[O]vni: Points: "+ Ovni.PUNTOS_OVNI+" - Harm: "+ 0 +" - Shield: "+Ovni.VIDA_OVNI+"\n"+
				game.getNave().toString()+": Harm (super-missile): "+UCMShipLaser.DANNO_LASER+" ("+ UCMShipSuperMisil.DANNO_LASER+ ")"+" - Shield: "+ UCMShip.VIDA_UCM;
				return dev;
	}
	@Override
	public Command parse(String[] s) throws CommandParseException {
		Command command = null;
		
		if(this.matchCommandName(s[0])){
			command = new ListCommand();
			if(s.length!=1) {
				throw new CommandParseException(incorrectNumArgsMsg);
			}
		}
		return command;
	}

	

}
