package simulator.modelo;

import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;

import simulator.control.Controller;
import simulator.model.Event;
import simulator.model.Road;
import simulator.model.RoadMap;
import simulator.model.TrafficSimObserver;

public class Crowdedness implements TrafficSimObserver{
	private Controller _ctrl;
	private static Map<Road,Integer> mapaCrowd;
	
	public Crowdedness(Controller controller) {
		_ctrl=controller;
		_ctrl.addObserver(this);
		mapaCrowd=new HashMap<Road,Integer>();
	}
	public static String getCrowdedness() {
		String s="";
		int i=0;
		for(Entry<Road, Integer> a:mapaCrowd.entrySet()) {
			s+="("+a.getKey().getId()+","+a.getValue()+")";
			if(i!=mapaCrowd.entrySet().size()-1)
				s+=", ";
			
			i++;
		}
			
		return s;
	}

	@Override
	public void onAdvanceStart(RoadMap map, List<Event> events, int time) {
		
	}

	@Override
	public void onAdvanceEnd(RoadMap map, List<Event> events, int time) {
		for(Road r: map.getRoads()) {
			if(mapaCrowd.containsKey(r))
				mapaCrowd.put(r,Math.max(mapaCrowd.get(r),r.getVehicles().size()));
			else {
				mapaCrowd.put(r, r.getVehicles().size());
			}
		}
		
	}

	@Override
	public void onEventAdded(RoadMap map, List<Event> events, Event e, int time) {
		
		
	}

	@Override
	public void onReset(RoadMap map, List<Event> events, int time) {
		
		
	}

	@Override
	public void onRegister(RoadMap map, List<Event> events, int time) {
		
	}

	@Override
	public void onError(String err) {
		// TODO Auto-generated method stub
		
	}

}
