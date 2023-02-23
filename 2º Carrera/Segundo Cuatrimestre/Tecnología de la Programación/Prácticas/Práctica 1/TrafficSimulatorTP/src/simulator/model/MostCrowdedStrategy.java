package simulator.model;

import java.util.List;

public class MostCrowdedStrategy implements LightSwitchingStrategy{
	private int timeSlot;
	
	public MostCrowdedStrategy(int timeSlot) {
		this.timeSlot=timeSlot;
	}
	@Override
	
	public int chooseNextGreen(List<Road> roads, List<List<Vehicle>> qs, int currGreen, int lastSwitchingTime, int currTime) {
		int dev=0;
		if(roads.isEmpty()) {
			dev=-1;
		}
		else if(currGreen==-1) {
			int Indmax=0;
			for(int i=1; i<qs.size();i++) {
				if(qs.get(Indmax).size()<qs.get(i).size()) {
					Indmax=i;
				}
			}
			dev=Indmax;
		}else if(currTime-lastSwitchingTime<timeSlot) {
			dev=currGreen;
		}else {
			int Indmax=0;
			for(int i=1; i<qs.size();i++) {
				if(qs.get((currGreen+1+Indmax)%qs.size()).size()<qs.get((currGreen+1+i)%qs.size()).size()) {
					Indmax=i;
				}
			}
			dev=(currGreen+1+Indmax)%qs.size();
		}
		return dev;
	}
	

}
