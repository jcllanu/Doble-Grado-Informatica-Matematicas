package tp.tp1.controller.commands;

import tp.tp1.controller.Controller;
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
	public boolean execute(Game game, Controller controller) {//devuelve un booleano diciendo si te sales del tablero o no
		return game.move(this.desplazamiento);
		
	
	}
	
	@Override
	public Command parse(String[] s) {
		Command command = null;
		if(this.matchCommandName(s[0])){
			if(s.length>2) {/*AQUÍ HABRÁ QUE PONER ALGUNA EXCEPCIÓN*/
				if(s[1].contentEquals("right")||s[1].contentEquals("d")||s[1].contentEquals("left")||s[1].contentEquals("i")) {
					if (s[2].contentEquals("2")||s[2].contentEquals("1")){
						command = new MoveCommand(Integer.parseInt(s[2])*direccion(s[1]));
					}
				}
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
