package tp.tp1.view;

import tp.tp1.game.Game;

public class Stringifier extends GamePrinter{
	
	public Stringifier(Game g){
		this.game=g;
	}
	public Stringifier() {
		
	}
	public String toString() {
		String dev="— Space Invaders v2.0 — \n\n";
		dev+=this.game.serialize();
		return dev;
	}
	
	protected void prepareToString(Game g) {
		
	}
}
