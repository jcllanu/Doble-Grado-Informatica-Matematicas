package tp.tp1.game;

public enum Move {
	LEFT, RIGHT, DOWN;

	public static Move parse(String string) {
		if(string.equalsIgnoreCase("left")) {
			return LEFT;
		}else if(string.equalsIgnoreCase("right")) {
			return RIGHT;
		}else if(string.equalsIgnoreCase("down")) {
			return DOWN;
		}else {
			return null;
		}
	}
}
