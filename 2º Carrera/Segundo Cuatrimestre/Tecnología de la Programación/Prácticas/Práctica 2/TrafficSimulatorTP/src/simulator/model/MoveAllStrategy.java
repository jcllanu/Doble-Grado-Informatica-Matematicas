package simulator.model;

import java.util.LinkedList;
import java.util.List;

public class MoveAllStrategy implements DequeuingStrategy{
	public MoveAllStrategy() {
		
	}

	@Override
	public List<Vehicle> dequeuing(List<Vehicle> l) {
		List<Vehicle> dev=new LinkedList<Vehicle>();
		for(Vehicle v: l) {
			dev.add(v);
		}
		return dev;
		
	}
	
}
