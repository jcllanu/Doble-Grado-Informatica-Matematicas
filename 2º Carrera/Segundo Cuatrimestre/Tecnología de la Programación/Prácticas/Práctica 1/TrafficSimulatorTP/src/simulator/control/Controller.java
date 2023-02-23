package simulator.control;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintStream;

import org.json.JSONArray;
import org.json.JSONObject;
import org.json.JSONTokener;

import simulator.factories.Factory;
import simulator.model.Event;
import simulator.model.TrafficSimulator;

public class Controller {
	private TrafficSimulator traficSim;
	private Factory<Event> factoriaEventos;
	
	
	public Controller(TrafficSimulator sim, Factory<Event> eventsFactory) {
		if(sim==null||eventsFactory==null){
			throw new IllegalArgumentException("Los valores no pueden ser null");
		}
		traficSim=sim;
		factoriaEventos=eventsFactory;
	}
	
	public void reset() {
		traficSim.reset();
	}
	
	public void loadEvents(InputStream in){
		JSONObject jo = new JSONObject(new JSONTokener(in));
		if(jo.has("events")){		
			JSONArray ja=jo.getJSONArray("events");
			for(int i=0; i<ja.length();i++){
				JSONObject evento=ja.getJSONObject(i);
				traficSim.addEvent(factoriaEventos.createInstance(evento));
			}
		}else{
			throw new IllegalArgumentException("Formato del JSON invalido");
		}
	}
	
	public void run (int n,OutputStream os) throws IOException {
		PrintStream ps = new PrintStream(os);
		ps.println("{\"states\": [");
		ps.flush();
		for(int i=0; i<n; i++){
			traficSim.advance();
			ps.println(traficSim.report()+(i!=n-1? ",":"]}"));
			ps.flush();
			
		}
	}
	
}
