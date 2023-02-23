package simulator.model;

import java.awt.RenderingHints;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;

import org.json.JSONArray;
import org.json.JSONObject;

public class Junction extends SimulatedObject{
	
	private List<Road> listInRoads;
	private Map<Junction,Road> mapOutRoad;
	private List<List<Vehicle>> listaColas;
	private Map<Road,List<Vehicle>> mapaColas;
	private int indSemaforo;
	private int ultimPasCambSemaforo;
	private LightSwitchingStrategy estrategiaSemaforo;
	private DequeuingStrategy estrategiaDescolar;
	private int x;
	private int y;
	
	
	
	Junction(String id, LightSwitchingStrategy lsStrategy, DequeuingStrategy dqStrategy, int xCoor, int yCoor) {
			super(id);
			if(lsStrategy==null||dqStrategy==null||xCoor<0||yCoor<0) {
				new IllegalArgumentException("lsStrategy, dqStrategy, xCoor e yCoor deben ser argumentos validos");;
			}
			listInRoads=new LinkedList<Road>();
			mapOutRoad=new HashMap<Junction,Road>();
			listaColas=new LinkedList<List<Vehicle >>();
			mapaColas=new HashMap<Road,List<Vehicle>>();
			ultimPasCambSemaforo=0;
			estrategiaSemaforo=lsStrategy;
			estrategiaDescolar=dqStrategy;
			x=xCoor;
			y=yCoor;
			indSemaforo=-1;
	}


	@Override
	void advance(int time) {
		if(indSemaforo>=0) {
			//Guarda los vehiculos que avanzan del semaforo que está actualmente en verde
			List<Vehicle> vehiculosQueSeMueven=estrategiaDescolar.dequeuing(listaColas.get(indSemaforo));
			for(Vehicle v: vehiculosQueSeMueven) {
				listaColas.get(indSemaforo).remove(v);
				mapaColas.get(v.getRoad()).remove(v);
				v.moveToNextRoad();
			}
		}
		int nextGreen=estrategiaSemaforo.chooseNextGreen(listInRoads, listaColas, indSemaforo, ultimPasCambSemaforo, time);
		if(nextGreen!=indSemaforo) {
			indSemaforo=nextGreen;
			ultimPasCambSemaforo=time;
		}
	}

	@Override
	public JSONObject report() {
		
		JSONObject j = new JSONObject();
		j.put("id", _id);
		if(indSemaforo==-1) {
			j.put("green", "none");
		}else {
			j.put("green", listInRoads.get(indSemaforo)._id);
		} 
		JSONArray colas = new JSONArray();
		for(int i=0; i<listaColas.size(); i++) {
			JSONObject qi = new JSONObject();
			qi.put("road", listInRoads.get(i)._id);
			JSONArray vehicles = new JSONArray();
			for(int k=0; k<listaColas.get(i).size();k++) {
				vehicles.put(listaColas.get(i).get(k)._id);
			}
			qi.put("vehicles", vehicles);
			colas.put(qi);
		}

		j.put("queues", colas);
		
		return j;
	}
	
	void addIncommingRoad(Road r) {
		if(r.getDest()._id==this._id) {
			listInRoads.add(r);
			List<Vehicle> cola1= new LinkedList<Vehicle>();
			List<Vehicle> cola2= new LinkedList<Vehicle>();
			listaColas.add(cola1);
			mapaColas.put(r, cola2);
		}else {
			throw new IllegalArgumentException("La carretera debe tener como cruce destino el cruce actual");
		}
	}
	
	void addOutGoingRoad(Road r) {
		if(r.getSrc()._id!=this._id||mapOutRoad.containsValue(r)||mapOutRoad.containsKey(r.getDest())) {
			throw new IllegalArgumentException("La carretera debe tener como cruce origen el cruce actual, no debe existir "
									+ "ya y no debe haber ninguna otra carretera que vaya al cruce destino desde este cruce");
		}else {
			mapOutRoad.put(r.getDest(), r);
		}
	}
	
	void enter(Vehicle v) {
		boolean encontrado=false;
		int contador=0;
		//Obtenemos la lista/cola de vehiculos que tiene como clave la carretera por la que circula v y 
		//añadimos v a esa cola
		mapaColas.get(v.getRoad()).add(v);
		
		while(!encontrado && contador<listInRoads.size()) {
			//Buscamos el índice dentro de la lista de carreteras entrantes de la carretera 
			//por la que va el vehiculo. Sabemos que el indice i de la lista de carreteras entrantes
			//se corresponde con el indice de la cola de vehiculos que llegan desde esa carretera
			//en la lista de colas. Es decir si la carretera entrante r1 está en la posicion 2 de 
			//listInRoads(listInRoads[2]==r1), entonces la lista/cola de vehiculos que vienen desde 
			//la carretera r1 está en la posicion 2 de la lista de colas (listColas[2]=cola de 
			//vehiculos que vienen de la carretera r1
			
			if(listInRoads.get(contador)==v.getRoad()) {
				encontrado=true;
			}else {
				contador++;
			}
		}
		if(encontrado) {
			listaColas.get(contador).add(v);
		}
		else {
			throw new IllegalArgumentException("Problema sin solucion");
		}
	}
	
	Road roadTo(Junction j) {
		return mapOutRoad.get(j);
	}
	
	public int getX() {
		return x;
	}
	public int getY() {
		return y;
	}


	public int getGreenLightIndex() {
		return indSemaforo;
	}


	public List<Road> getInRoads() {
		return listInRoads;
	}
	
	public String getListaColas(){
		String dev="";
		for(int i=0; i<listInRoads.size(); i++) {
			dev+=listInRoads.get(i).getId()+":[";
			for(int j=0; j<listaColas.get(i).size(); j++) {
				dev+=listaColas.get(i).get(j).getId();
				if(j!=listaColas.get(i).size()-1) {
					dev+=",";
				}
			}
			dev+="] ";
		}
		return dev;
	}
	
	
}
