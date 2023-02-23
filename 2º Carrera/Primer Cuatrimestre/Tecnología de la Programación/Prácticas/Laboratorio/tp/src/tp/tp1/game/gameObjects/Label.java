package tp.tp1.game.gameObjects;

public class Label{
	private int label;
	private Bomb bomba;
	private DestroyerAlien destroyer;
	
	public Label(int l, Bomb b, DestroyerAlien d) {
		setLabel(l);
		setBomba(b);
		setDestroyer(d);
	}

	public int getLabel() {
		return label;
	}

	public void setLabel(int label) {
		this.label = label;
	}

	public DestroyerAlien getDestroyer() {
		return destroyer;
	}

	public void setDestroyer(DestroyerAlien destroyer) {
		this.destroyer = destroyer;
	}

	public Bomb getBomba() {
		return bomba;
	}

	public void setBomba(Bomb bomba) {
		this.bomba = bomba;
	}
}
