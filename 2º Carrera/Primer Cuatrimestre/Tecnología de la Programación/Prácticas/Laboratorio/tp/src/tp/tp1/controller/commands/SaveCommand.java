package tp.tp1.controller.commands;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;

import tp.tp1.controller.Controller;
import tp.tp1.exceptions.CommandExecuteException;
import tp.tp1.exceptions.CommandParseException;
import tp.tp1.game.Game;
import tp.tp1.view.GamePrinter;
import tp.tp1.view.PrinterTypes;

public class SaveCommand extends Command{
	public static final String CommandText = "save";
	public static final String ShortCutText = "sv";
	public static final String CommandTextMsg = "[S]a[V]e <fileName>";
	public static final String HelpTextMsg = "The game is saved in a file named 'fileName.txt' ";
	public static final String SuccessfullySaved1="Game successfully saved in file ";
	public static final String SuccessfullySaved2=".dat. Use the load command to reload it";
	private String fileName;
	
	public SaveCommand(){
		super(CommandText, ShortCutText,CommandTextMsg, HelpTextMsg);
	}	

	
	public SaveCommand(String string) {
		super(CommandText, ShortCutText,CommandTextMsg, HelpTextMsg);
		fileName=string;
	}


	@Override
	public boolean execute(Game game, Controller controller) throws CommandExecuteException {/*REVISAR la excepción*/
		try {
		FileWriter file=new FileWriter(fileName+".dat");
		BufferedWriter bf=new BufferedWriter(file);
		GamePrinter print= PrinterTypes.SERIALIZER.getObject();
		print.setGame(game);
		file.write(print.toString());
		file.close();
		controller.mostrarPantalla(SuccessfullySaved1+fileName+SuccessfullySaved2);
	
		}catch(IOException e) {
			throw new CommandExecuteException("El archivo no se ha podido abrir/cerrar/escribir");
		}
		return false;
	}
	
	@Override
	public Command parse(String[] s) throws CommandParseException {
		Command command = null;
		if(this.matchCommandName(s[0])){
			
			if(s.length!=2) {
				throw new CommandParseException(incorrectNumArgsMsg);
			}else {
				command = new SaveCommand(s[1]);
			}
		}
		return command;
	}



}
