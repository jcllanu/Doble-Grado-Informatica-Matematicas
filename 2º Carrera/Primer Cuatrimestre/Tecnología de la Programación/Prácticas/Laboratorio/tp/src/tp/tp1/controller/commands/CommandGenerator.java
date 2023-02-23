package tp.tp1.controller.commands;

import tp.tp1.exceptions.CommandParseException;

public class CommandGenerator {

	public static final int NUM_COMMANDS = 14;
	
	private static Command[] availableCommands = {
			new ListCommand(),
			new HelpCommand(),
			new ResetCommand(),
			new ExitCommand(),
			new ShootCommand(),
			new MoveCommand(),
			new ShockwaveCommand(),
			new NoneCommand(),
			new BuySuperMissileCommand(),
			new StringifyCommand(),
			new ListPrintersCommand(),
			new SaveCommand(),
			new LoadCommand(),
			new RotateCommand()
			};
	
	public static Command parseCommand(String[ ] commandWords) throws CommandParseException {
		int cont = 0;
		boolean encontrado = false;
		Command command = null;
		
		try {
		while (cont<NUM_COMMANDS && !encontrado) {
			command = availableCommands[cont].parse(commandWords);
			if (command!=null) {
				encontrado = true;
			}
			cont++;
		}
		}catch(CommandParseException e) {
			throw e;
		}
		return command;
	}
	public static String commandHelp() {
		String devolver="";
		for(int i=0; i<NUM_COMMANDS; i++) {
		devolver+= availableCommands[i].helpText();
		}
		return devolver;
	}
	
}
