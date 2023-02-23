package tp.tp1.controller.commands;

import java.io.BufferedReader;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import tp.tp1.controller.Controller;
import tp.tp1.exceptions.CommandExecuteException;
import tp.tp1.exceptions.CommandParseException;
import tp.tp1.exceptions.FileContentsException;
import tp.tp1.game.Game;
import tp.tp1.game.gameObjects.AlienShip;
import tp.tp1.game.gameObjects.UCMShipSuperMisil;


public class LoadCommand extends Command{
	public static final String CommandText = "load";
	public static final String ShortCutText = "ld";
	public static final String CommandTextMsg = "[L]oa[d] <fileName>";
	public static final String HelpTextMsg = "The game 'fileName.txt' is loaded. ";
	public static final String SuccessfullyLoaded1="Game successfully loaded from file ";
	public static final String SuccessfullyLoaded2=".dat.";
	private String fileName;
	
	public LoadCommand(){
		super(CommandText, ShortCutText,CommandTextMsg, HelpTextMsg);
	}	

	public LoadCommand(String string) {
		super(CommandText, ShortCutText,CommandTextMsg, HelpTextMsg);
		fileName = string;
	}

	@Override
	public boolean execute(Game game, Controller controller) throws CommandExecuteException {/*HACER*/
		FileReader file=null;
		BufferedReader bf=null;
		Game gameNuevo=new Game();
		int numAl=AlienShip.getNumAlien(),numMis=UCMShipSuperMisil.getNumSuperMisil();
		try {
			file=new FileReader(fileName+".dat");
			bf=new BufferedReader(file);
			bf.readLine();
			bf.readLine();
			try {
				gameNuevo.load(bf);
				controller.setGame(gameNuevo);
			} catch (FileContentsException e) {
				controller.setGame(game);
				AlienShip.setNumAlien(numAl);
				UCMShipSuperMisil.setNumSuperMisil(numMis);
				throw new CommandExecuteException("Cannot load the game: ",e);
			}
			
		
		}catch(FileNotFoundException e) {
			controller.setGame(game);
			AlienShip.setNumAlien(numAl);
			UCMShipSuperMisil.setNumSuperMisil(numMis);
			throw new CommandExecuteException("Cannot load the game: File not found.");
			
		}catch(IOException e){
			controller.setGame(game);
			AlienShip.setNumAlien(numAl);
			UCMShipSuperMisil.setNumSuperMisil(numMis);
			throw new CommandExecuteException("Cannot load the game: Unkown cause.");
		}
		finally {
			try{                    
	            if( null != file ){   
	               file.close();     
	            }
	           
	         }catch (IOException e){ 
	        	 controller.setGame(game);
	        	 AlienShip.setNumAlien(numAl);
				UCMShipSuperMisil.setNumSuperMisil(numMis);
	        	 throw new CommandExecuteException("Cannot load the game: Error while closing the file.");
	         }
		}
		System.out.println(gameNuevo.data());
		controller.getPrinter().setGame(gameNuevo);
		System.out.println(controller.getPrinter());
		controller.mostrarPantalla(SuccessfullyLoaded1+fileName+SuccessfullyLoaded2);
		return false;
	}
	
	@Override
	public Command parse(String[] s) throws CommandParseException {
		Command command = null;
		if(this.matchCommandName(s[0])){
			
			if(s.length!=2) {
				throw new CommandParseException(incorrectNumArgsMsg);
			}else {
				command = new LoadCommand(s[1]);
			}
		}
		return command;
	}



}

