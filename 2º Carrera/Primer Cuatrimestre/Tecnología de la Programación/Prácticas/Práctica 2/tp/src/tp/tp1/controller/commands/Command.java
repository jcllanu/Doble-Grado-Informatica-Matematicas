package tp.tp1.controller.commands;
import tp.tp1.controller.Controller;
import tp.tp1.game.*;

abstract public class Command {
	protected final String name;
	protected final String shortCut;
	protected final String details;
	protected final String help;
	
	protected static final String incorrectNumArgsMsg = "Incorrect number of arguments";
	protected static final String incorrectArgsMsg = "Incorrect argument format";
	
	public Command(String name, String shortcut, String details, String help){
		this.name = name;
		this. shortCut = shortcut;
		this.details = details;
		this.help = help;
		}

	public abstract boolean execute(Game g, Controller c);
	
	public abstract Command parse(String [] s) ;
	
	protected boolean matchCommandName(String name) {
		return this.shortCut.equalsIgnoreCase(name) || this.name.equalsIgnoreCase(name);
	}

	public String helpText() {
		return details + " : " + help + "\n";
	}
}


