package simulator.model;


import java.util.List;

import org.json.JSONObject;

import simulator.misc.SortedArrayList;

public class TrafficSimulator {
	
	private RoadMap mapaCarreteras;
	private List<Event> listaEventos;
	private int time;
	
	public TrafficSimulator() {
		time=0;
		mapaCarreteras=new RoadMap();
		listaEventos=new SortedArrayList<Event>();
	}
	
	public void reset() {
		mapaCarreteras.reset();
		listaEventos.clear();
		time=0;
	}
	
	public void addEvent(Event e) {
		listaEventos.add(e);
	}
	
	public void advance() {
		time++;
		while(!listaEventos.isEmpty()&&listaEventos.get(0)._time==time) {
			listaEventos.get(0).execute(mapaCarreteras);
			listaEventos.remove(0);
		}
		for(Junction j: mapaCarreteras.getJunctions()){
			j.advance(time);
		}
		for(Road r: mapaCarreteras.getRoads()){
			r.advance(time);
		}
		
	}
	
	public JSONObject report(){
		JSONObject j = new JSONObject();
		j.put("time", time);
		j.put("state", mapaCarreteras.report());
		
		return j;
		
	}
}
