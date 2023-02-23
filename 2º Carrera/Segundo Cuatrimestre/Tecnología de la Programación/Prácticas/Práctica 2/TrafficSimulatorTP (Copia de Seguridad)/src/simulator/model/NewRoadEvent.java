package simulator.model;

public abstract class NewRoadEvent extends Event{
	protected String id;
	protected String srcJunc;
	protected String destJunc;
	protected int length;
	protected int co2Limit;
	protected int maxSpeed;
	protected Weather weather;
	protected Junction src;
	protected Junction dest;
	public NewRoadEvent(int time, String id, String srcJunc, String destJunc, int length, int co2Limit, int maxSpeed, Weather weather) {
		super(time);
		this.srcJunc=srcJunc;
		this.destJunc=destJunc;
		this.length=length;
		this.co2Limit=co2Limit;
		this.maxSpeed=maxSpeed;
		this.weather=weather;
		this.id=id;
	}
	
	void execute(RoadMap map) {
		dest=map.getJunction(destJunc);
		src=map.getJunction(srcJunc);
		map.addRoad(createRoadObject());
	}
	
	protected abstract Road createRoadObject();
	
	abstract public String toString();
}
