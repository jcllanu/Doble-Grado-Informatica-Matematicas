package tp.tp1.controller.commands;

import tp.tp1.controller.Controller;
import tp.tp1.exceptions.CommandParseException;
import tp.tp1.game.Game;
import tp.tp1.view.PrinterTypes;

public class ListPrintersCommand extends Command{
	public static final String CommandText = "listprinters";
	public static final String ShortCutText = "lp";
	public static final String CommandTextMsg = "[L]ist[P]rinters";
	public static final String HelpTextMsg = "Prints the list of available printer types.";
	
	
	public ListPrintersCommand() {
		super(CommandText, ShortCutText,CommandTextMsg, HelpTextMsg);
	}

	@Override
	public boolean execute(Game g, Controller c) {
		c.mostrarPantalla(PrinterTypes.printerHelp(g));
		return false;
	}

	@Override
	public Command parse(String[] s) throws CommandParseException {
		Command command = null;
	
		if(this.matchCommandName(s[0])){
			command = new ListPrintersCommand();
			if(s.length!=1) {
				throw new CommandParseException(incorrectNumArgsMsg);
			}
		}
		
		return command;
	}

}
