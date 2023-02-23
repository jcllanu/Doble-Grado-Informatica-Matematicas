package tp.tp1.controller.commands;

public class CommandGenerator {

	public static final int NUM_COMMANDS = 9;
	
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
			};
	
	public static Command parseCommand(String[ ] commandWords) {
		int cont = 0;
		boolean encontrado = false;
		Command command = null;
		
		while (cont<NUM_COMMANDS && !encontrado) {
			command = availableCommands[cont].parse(commandWords);
			if (command!=null) {
				encontrado = true;
			}
			cont++;
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
