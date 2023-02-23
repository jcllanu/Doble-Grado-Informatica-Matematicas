package simulator.model;


import java.util.ArrayList;
import java.util.List;


import org.json.JSONObject;

import simulator.misc.SortedArrayList;

public class TrafficSimulator implements Observable<TrafficSimObserver> {
	
	private RoadMap mapaCarreteras;
	private List<Event> listaEventos;
	private List<TrafficSimObserver> observadores;
	private int time;
	
	public TrafficSimulator() {
		time=0;
		mapaCarreteras=new RoadMap();
		listaEventos=new SortedArrayList<Event>();
		observadores=new ArrayList<TrafficSimObserver>();
	}
	
	public void reset() {
		mapaCarreteras.reset();
		listaEventos.clear();
		time=0;
		
		notifyOnReset();
		
	}
	
	public void addEvent(Event e) {
		if(e._time<time) {
			String err="El tiempo del nuevo evento es menor al tiempo actual de ejecución";
			notifyOnError(err);
			throw new IllegalArgumentException(err);
		}else {
			listaEventos.add(e);
			notifyOnEventAdded(e);
		}
	}
	
	public void advance() {
		time++;
		notifyOnAdvanceStart();
		
		try{
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
		}catch(Exception e) {
			
			notifyOnError(e.getMessage());
			throw new IllegalArgumentException(e.getMessage());
		}
		notifyOnAdvanceEnd();
	}
	
	public JSONObject report(){
		JSONObject j = new JSONObject();
		j.put("time", time);
		j.put("state", mapaCarreteras.report());
		
		return j;
		
	}

	@Override
	public void addObserver(TrafficSimObserver o) {
		observadores.add(o);
		o.onRegister(mapaCarreteras, listaEventos, time);
		
	}

	@Override
	public void removeObserver(TrafficSimObserver o) {
		observadores.remove(o);
	}
	
	
	//Notificaciones a los observadores
	
	private void notifyOnError(String err) {
		for(TrafficSimObserver observador: observadores) {
			observador.onError(err);	
		}
	}
	
	private void notifyOnAdvanceEnd() {
		for(TrafficSimObserver observador: observadores) {
			observador.onAdvanceEnd(mapaCarreteras, listaEventos, time);
		}
	}
	
	
	private void notifyOnAdvanceStart() {
		for(TrafficSimObserver observador: observadores) {
			observador.onAdvanceStart(mapaCarreteras, listaEventos, time);
		}
	}
	
	private void notifyOnReset() {
		for(TrafficSimObserver observador: observadores) {
			observador.onReset(mapaCarreteras, listaEventos, time);
		}
	}
	

	private void notifyOnEventAdded(Event e) {
		for(TrafficSimObserver observador: observadores) {
			observador.onEventAdded(mapaCarreteras, listaEventos, e, time);
		}
	}
}
