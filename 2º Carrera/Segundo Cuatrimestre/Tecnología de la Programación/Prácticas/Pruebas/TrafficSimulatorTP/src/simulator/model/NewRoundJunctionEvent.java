package simulator.model;

public class NewRoundJunctionEvent extends Event {
	private String id;
	private int xCoor;
	private int yCoor;
	
	public NewRoundJunctionEvent(int time, String id, int xCoor, int yCoor) {
		super(time);
		this.id=id;
		this.xCoor=xCoor;
		this.yCoor=yCoor;
	}

	@Override
	void execute(RoadMap map) {
		Junction j=new CruceConRotonda(id, xCoor, yCoor);
		map.addJunction(j);
	}

	@Override
	public String toString() {
		return "New RoundJunction '"+ id +"'";
	}

	

}
