package tp.tp1.game;

import tp.tp1.Level;

public class FileContentsVerifier {
	
	public static final String separator1 = ";";
	public static final String separator2 = ",";
	public static final String labelRefSeparator = " - ";
	// for robustness
	
	public static final String readSeparator1 = "\\s*"+ separator1 + "\\s*";
	public static final String readSeparator2 = "\\s*"+ separator2 + "\\s*";
	public static final String readLabelRefSeparator = "\\s*"+ "-" + "\\s*";
	private String foundInFileString = "";
	
	
	private void appendToFoundInFileString(String linePrefix) {
		foundInFileString += linePrefix;
	}
	// Don’t catch NumberFormatException.
	
	public boolean verifyCycleString(String cycleString) {
		String[] words = cycleString.split (readSeparator1);
		appendToFoundInFileString(words[0]);
		if (words.length != 2 || ! verifyCurrentCycle(Integer.parseInt(words[1]))) {
			return false;
		}	
		return true;
	}
	
	
	public boolean verifyLevelString(String levelString) {
		String[] words = levelString. split (readSeparator1);
		appendToFoundInFileString(words[0]);
		if (words.length != 2 || ! verifyLevel (Level.parse(words[1]))) {
			return false;
		}
		return true;
	}
	
	// Don’t catch NumberFormatException.
	
	public boolean verifyOvniString(String lineFromFile, Game game, int armour) {
		String[] words = lineFromFile.split(readSeparator1);
		appendToFoundInFileString(words[0]);
		if (words.length != 4) return false;
			String[] coords = words[2].split (readSeparator2);
			
			if (!verifyBool(words[1])){
				return false;
			}else {
				if(words[1].equals("true")) {
					if(!verifyCoords(Integer. parseInt(coords[0]) , Integer. parseInt(coords[1]) , game)
								|| ! verifyLives (Integer.parseInt(words[3]), armour)){
						return false;			
					}
				}else {
					Integer. parseInt(coords[0]);/*COMPROBAR QUE NO SALTA NUMBER FORMATT EXCEPTION??*/
					Integer. parseInt(coords[1]);
					Integer.parseInt(words[3]);
				}
			}
		return true;
	}
	
	// Don’t catch NumberFormatException.
	public boolean verifyPlayerString(String lineFromFile, Game game, int armour) {
		String[] words = lineFromFile.split(readSeparator1);
		appendToFoundInFileString(words[0]);
	
		if (words.length != 6) {
			return false;
		}
		String[] coords = words[1].split (readSeparator2);
		if ( ! verifyCoords(Integer. parseInt(coords[0]) , Integer. parseInt(coords[1]) , game)
		|| ! verifyLives (Integer. parseInt(words[2]), armour)
		|| ! verifyPoints (Integer. parseInt(words[3]))
		|| ! verifyBool(words[4])
		|| ! verifyNumSuperMisiles(Integer. parseInt(words[5]))) {
			return false;
		}
	
	return true;
	}
	
	
	private boolean verifyNumSuperMisiles(int i) {
		return i>=0;
	}
	// Don’t catch NumberFormatException.
	public boolean verifyAlienShipString(String lineFromFile, Game game, int armour) {/*CAMBADO PORQUE NO GUARDAMOS LA DIR NI LOS CICLOS*/
		String[] words = lineFromFile.split(readSeparator1);
		appendToFoundInFileString(words[0]);
		if (words.length !=3) {
			return false;
		}
		String[] coords = words[1].split (readSeparator2);
		if ( ! verifyCoords(Integer. parseInt(coords[0]) , Integer. parseInt(coords[1]) , game)
		|| ! verifyLives (Integer. parseInt(words[2]), armour) ) {
		return false;
		}
	return true;
	}
	// Don’t catch NumberFormatException.
	public boolean verifyWeaponString(String lineFromFile, Game game) {
		String[] words = lineFromFile.split(readSeparator1);
		if (words.length != 2) {
			return false;
		}
		appendToFoundInFileString(words[0]);
		String[] coords = words[1].split (readSeparator2);
		if ( ! verifyCoords(Integer. parseInt(coords[0]) , Integer. parseInt(coords[1]) , game) ) {
			return false;
		}
		
	return true;
	}
	public boolean verifyRefString(String lineFromFile) {
		String[] words = lineFromFile.split(readLabelRefSeparator);
		if (words.length != 2 || ! verifyLabel(words[1])) {
			return false;
		}
		return true;
	}
	public static boolean verifyLabel(String label) {
		return Integer.parseInt(label) > 0;
	}
	public static boolean verifyCoords(int x, int y, Game game) {
		return game.isOnBoard(x, y);
	}
	
	public static boolean verifyCurrentCycle(int currentCycle) {
		return currentCycle >= 0;
	}
	public static boolean verifyLevel(Level level) {
		return level != null;
	}
	public static boolean verifyDir(Move dir) {
		return dir != null;
	}
	public static boolean verifyLives(int live, int armour) {
		return 0 < live && live <= armour;
	}
	public static boolean verifyPoints(int points) {
		return points >= 0;
	}
	public static boolean verifyCycleToNextAlienMove(int cycle, Level level) {
	return 0 <= cycle && cycle <= level.getVelocidad();
	}
	// parseBoolean converts any string different from "true " to false .
	public static boolean verifyBool(String boolString) {
		return boolString.equals("true") || boolString.equals("false");
	}
	public boolean isMissileOnLoadedBoard() {
		return foundInFileString.toUpperCase().contains("M") || foundInFileString.toUpperCase().contains("X");
	}
	// Use a regular expression to verify the string of concatenated prefixes found
	public boolean verifyLines() {
	// TO DO: compare foundInFileString with a regular expression
	return true;
	}
	// text explaining allowed concatenated prefixes
	public String toString() {
	// TO DO
	return "";
}
}