package tp.tp1.game.characters;

public class Bomb {
	public final static int DANNO_BOMB = 1;
	
	private int fil;
	private int col;
	private int dano;
	private DestroyerAlien padre;
	
	public Bomb(DestroyerAlien alien) {
		this.dano = DANNO_BOMB;
		this.setCol(alien.getCol());
		this.setFil(alien.getFil());
		this.padre=alien;

	}
	
	public void movimiento() {
		this.setFil(this.getFil() + 1);
	}
	public String toString() {
		return ".";
	}

	public int getFil() {
		return fil;
	}

	public void setFil(int fil) {
		this.fil = fil;
	}

	public int getCol() {
		return col;
	}

	public void setCol(int col) {
		this.col = col;
	}
	

	public DestroyerAlien getPadre() {
		return padre;
		
	}
}
