package simulator.model;

import java.util.List;

public class RoundRobinStrategy implements LightSwitchingStrategy{
	private int timeSlot;
	
	public RoundRobinStrategy(int timeSlot) {
		this.timeSlot=timeSlot;
	}

	@Override
	public int chooseNextGreen(List<Road> roads, List<List<Vehicle>> qs, int currGreen, int lastSwitchingTime, int currTime) {
		int dev=0;
		if(roads.isEmpty()) {
			dev=-1;
		}
		else if(currGreen==-1) {
			dev=0;
		}else if(currTime-lastSwitchingTime<timeSlot) {
			dev=currGreen;
		}else {
			dev=(currGreen+1)%roads.size();
		}
		return dev;
	}

	
}
