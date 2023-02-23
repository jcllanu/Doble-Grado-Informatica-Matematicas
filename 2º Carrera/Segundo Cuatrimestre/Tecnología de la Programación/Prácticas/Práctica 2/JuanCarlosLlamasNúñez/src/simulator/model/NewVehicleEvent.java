package simulator.model;

import java.util.LinkedList;
import java.util.List;

public class NewVehicleEvent extends Event{
	private String id;
	private int maxSpeed;
	private int contClass;
	private List<String> itinerary;
	private List<Junction> itinerario;
	public NewVehicleEvent(int time, String id, int maxSpeed, int contClass, List<String> itinerary) { 
		super(time); 
		this.id=id;
		this.maxSpeed=maxSpeed;
		this.contClass=contClass;
		this.itinerary=itinerary;
		itinerario=new LinkedList<Junction>();
	}
	


	@Override
	void execute(RoadMap map) {
		for(int i=0; i<itinerary.size(); i++) {
			itinerario.add(map.getJunction(itinerary.get(i)));
		}
		Vehicle v=new Vehicle(id, maxSpeed, contClass, itinerario);
		map.addVehicle(v);
		v.moveToNextRoad();
	}
	
	@Override
	public String toString() {
		return "New Vehicle '"+ id +"'";
	}

}
