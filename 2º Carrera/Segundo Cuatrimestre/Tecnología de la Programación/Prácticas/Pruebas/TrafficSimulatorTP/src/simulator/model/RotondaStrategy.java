package simulator.model;

import java.util.List;

public class RotondaStrategy implements LightSwitchingStrategy{

	@Override
	public int chooseNextGreen(List<Road> roads, List<List<Vehicle>> qs, int currGreen, int lastSwitchingTime,
			int currTime) {
		int dev=0;
		if(roads.isEmpty()) {
			dev=-1;
		}
		else if(currGreen==-1) {
			dev=0;
		}else if(qs.get(currGreen).size()>0) {
			dev=currGreen;
		}else {
			boolean encontrado=false;
			int i=currGreen+1;
			while(!encontrado && i%qs.size()!=currGreen) {
				if(qs.get( i%qs.size()).size()==0) {
					i++;
				}else {
					encontrado=true;
				}
			}
			if(!encontrado)
				dev=currGreen+1;
			else
				dev=i%qs.size();
		}
		return dev;
	}

}
