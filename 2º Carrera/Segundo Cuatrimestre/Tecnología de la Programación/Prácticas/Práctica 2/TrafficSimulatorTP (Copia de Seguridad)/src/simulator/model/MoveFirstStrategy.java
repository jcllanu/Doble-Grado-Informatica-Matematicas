package simulator.model;

import java.util.LinkedList;
import java.util.List;

public class MoveFirstStrategy implements DequeuingStrategy{
	public MoveFirstStrategy() {
		
	}
	

	@Override
	public List<Vehicle> dequeuing(List<Vehicle> l) {
		List<Vehicle> dev=new LinkedList<Vehicle>();
		if(l.size()>0) {
			dev.add(l.get(0));
		}
		return dev;
	}

}
