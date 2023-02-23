package simulator.model;

import java.util.Collections;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;

import org.json.JSONArray;
import org.json.JSONObject;

public class RoadMap {
	private List<Junction> listJunc;
	private List<Road> listRoad;
	private List<Vehicle> listVehic;
	private List<Junction> copialistJunc;
	private List<Road> copialistRoad;
	private List<Vehicle> copialistVehic;
	private Map<String,Junction> mapJunctions;
	private Map<String,Road> mapRoads;
	private Map<String,Vehicle> mapVehicles;
	
	
	public RoadMap(){
		listJunc=new LinkedList<Junction>();
		listRoad=new LinkedList<Road>();
		listVehic=new LinkedList<Vehicle>();
		mapJunctions=new HashMap<String,Junction>();
		mapRoads=new HashMap<String,Road>();
		mapVehicles=new HashMap<String,Vehicle>();
		copialistRoad=Collections.unmodifiableList(listRoad);
		copialistJunc=Collections.unmodifiableList(listJunc);
		copialistVehic=Collections.unmodifiableList(listVehic);
	}
	
	void reset() {
		listJunc.clear();
		listRoad.clear();
		listVehic.clear();
		mapJunctions.clear();
		mapVehicles.clear();
		mapRoads.clear();
	}
	
	void addJunction(Junction j) {
		if(mapJunctions.containsKey(j._id)) {
			throw new IllegalArgumentException("Este cruce ya existe");
				
		}else {
			mapJunctions.put(j._id, j);
			listJunc.add(j);
		}
	}
	
	void addRoad(Road r) {
		if(mapRoads.containsKey(r._id)||!mapJunctions.containsKey(r.getDest()._id)||!mapJunctions.containsKey(r.getSrc()._id)) {
			throw new IllegalArgumentException("Esta carretera existe o no puede construirse");
				
		}else {
			mapRoads.put(r._id, r);
			listRoad.add(r);
		}
	}
	
	void addVehicle(Vehicle v) {
		boolean ok=true;
		for(int i=0; i<v.getItinerary().size()-1; i++) {
			if(!mapJunctions.containsKey(v.getItinerary().get(i)._id) ||!mapJunctions.containsKey(v.getItinerary().get(i+1)._id)) {
				ok=false;
			}
			if(!mapRoads.containsKey(v.getItinerary().get(i).roadTo(v.getItinerary().get(i+1))._id)){
				ok=false;
			}
		}
		if(!ok||mapVehicles.containsKey(v._id)) {
			throw new IllegalArgumentException("Esta vehiculo existe o no puede construirse");
				
		}else {
			mapVehicles.put(v._id, v);
			listVehic.add(v);
		}
	}
	
	public Junction getJunction(String id) {
		return mapJunctions.get(id);

	}
	public Road getRoad(String id) {
		return mapRoads.get(id);
		
	}
	public Vehicle getVehicle(String id) {
		return mapVehicles.get(id);
		
	}
	public List<Junction>getJunctions(){
		
		return copialistJunc;		
	}
	public List<Road>getRoads(){
		return copialistRoad;
		
	}
	public List<Vehicle>getVehicles(){
		return copialistVehic;
		
	}
	public JSONObject report() {
		JSONObject j = new JSONObject();
		JSONArray arr1 = new JSONArray();
		for(Junction ju: listJunc) {
			arr1.put(ju.report());
		}
		j.put("junctions", arr1);
		
		JSONArray arr2 = new JSONArray();
		for(Road r: listRoad) {
			arr2.put(r.report());
		j.put("roads", arr2);
		
		JSONArray arr3 = new JSONArray();
		for(Vehicle v: listVehic) {
			arr3.put(v.report());
		}
		j.put("vehicles", arr3);
		
		
		
	}
		return j;
}
	}
