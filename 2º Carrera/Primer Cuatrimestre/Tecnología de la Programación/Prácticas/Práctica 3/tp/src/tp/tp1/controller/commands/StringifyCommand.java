package tp.tp1.controller.commands;

import tp.tp1.controller.Controller;
import tp.tp1.exceptions.CommandParseException;
import tp.tp1.game.Game;
import tp.tp1.view.GamePrinter;
import tp.tp1.view.Stringifier;

public class StringifyCommand extends Command{
	public static final String CommandText = "stringify";
	public static final String ShortCutText = "st";
	public static final String CommandTextMsg = "[St]ringify";
	public static final String HelpTextMsg = "Prints the game on stringify format.";
	
	public StringifyCommand() {
		super(CommandText, ShortCutText,CommandTextMsg, HelpTextMsg);
	}

	@Override
	public boolean execute(Game g, Controller c) {
		GamePrinter print=new Stringifier(g);
		System.out.println(print.toString());
		return false;
	}

	@Override
	public Command parse(String[] s) throws CommandParseException {
		Command command = null;
		if(this.matchCommandName(s[0])){
			command = new StringifyCommand();
			if(s.length!=1) {
				throw new CommandParseException(incorrectNumArgsMsg);
			}
		}
		return command;
	}
}
