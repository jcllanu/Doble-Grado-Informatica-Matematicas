package simulator.model;

import java.util.Collections;
import java.util.Comparator;
import java.util.List;

import org.json.JSONObject;

public class Vehicle extends SimulatedObject /*implements Comparable<Vehicle>*/{
	private List<Junction> itinerario;
	private List<Junction> copiaItinerario;
	private int velMax;
	private int velActual;
	private VehicleStatus estado;
	private Road road;
	private int localizacion;
	private int gradContaminacion;
	private int contamTotal;
	private int distRecorrida;
	private int siguienteCruce;
	
	Vehicle(String id, int maxSpeed, int contClass, List<Junction> itinerary) {
			super(id);
		if(maxSpeed<=0||contClass<0||contClass>10||itinerary.size()<2) {
			throw new IllegalArgumentException("maxSpeed, contClass e itinerary deben ser argumentos correctos");
		}
		copiaItinerario=Collections.unmodifiableList(itinerary);
		velMax=maxSpeed;
		gradContaminacion=contClass;
		itinerario=itinerary;
		
		velActual=0;
		estado=VehicleStatus.PENDING;
		road=null;
		localizacion=0;
		contamTotal=0;
		distRecorrida=0;
		siguienteCruce=0;
	}
	
	
	
	/*public int compareTo(Vehicle v) {
		if(v.getLocalizacion()==this.getLocalizacion()) {
			return 0;
		}else if(v.getLocalizacion()>this.getLocalizacion()) {
			return 1;
		}else {
			return -1;
		}
	}*/
	
	void setSpeed(int s) {
		if(estado==VehicleStatus.TRAVELING) {
			if(s<0) {
				throw new IllegalArgumentException("La velocidad debe ser no negativa");
			}
			if(s<velMax) {
				velActual=s;
			}else {
				velActual=velMax;
			}
		}else {
			velActual=0;
		}
	}
	
	void setContaminationClass(int c) {
		if(c<0||c>10) {
			throw new IllegalArgumentException("El grado de cntaminacion debe estar entre 0 y 10 (incluidos)");
		}else {
			gradContaminacion=c;
		}
	}
	
	void moveToNextRoad() {
		if(estado!=VehicleStatus.PENDING && estado!=VehicleStatus.WAITING) {
			throw new IllegalArgumentException("Para cambiar a un vehiculo de carretera debe estar PENDING o WATING (ni TRAVELLING ni ARRIVED)");
		}
		else {
			velActual=0;
			if(estado==VehicleStatus.PENDING) {//Pasa a la primera carretera
				road=copiaItinerario.get(0).roadTo(copiaItinerario.get(1));
				siguienteCruce=2;
				localizacion=0;
				road.enter(this);
				estado=VehicleStatus.TRAVELING;
				
			}else if(siguienteCruce==copiaItinerario.size()){//Llega a destino
				road.exit(this);
				estado=VehicleStatus.ARRIVED;
				
			}else {//Pasa a la siguiente carretera
				road.exit(this);
				road=road.getDest().roadTo(copiaItinerario.get(siguienteCruce));
				localizacion=0;
				road.enter(this);
				siguienteCruce++;
				estado=VehicleStatus.TRAVELING;
			}
		}
	}
	
	@Override
	void advance(int time) {
		int locAnt=getLocalizacion();
		if(estado==VehicleStatus.TRAVELING) {
			if(velActual+getLocalizacion()<road.getLength()) {
				localizacion = getLocalizacion() + velActual;
			}else {//Llega al final de la carretera
				localizacion=road.getLength();
				
				road.getDest().enter(this);
				estado=VehicleStatus.WAITING;
				velActual=0;
			}
			
		distRecorrida+=(getLocalizacion()-locAnt);
		
		int cont=(getLocalizacion()-locAnt)*gradContaminacion;
		contamTotal+=cont;
		road.addContamination(cont);
		}
	}

	@Override
	public JSONObject report() {
		JSONObject j = new JSONObject();
		j.put("id", _id);
		j.put("speed", velActual);
		j.put("distance", distRecorrida);
		j.put("co2", contamTotal);
		j.put("class", gradContaminacion);
		j.put("status", estado);
		
		if(!(estado==VehicleStatus.PENDING||estado==VehicleStatus.ARRIVED)) {
			j.put("road",road._id );
			j.put("location",getLocalizacion() );
		}
		return j;
	}
	
	
	public int getSpeed() {
		return velActual;
		
	}
	public int getMaxSpeed() {
		return velMax;
		
	}
	public int getContClass() {
		return gradContaminacion;
		
	}
	
	public VehicleStatus getStatus() {
		return estado;
		
	}
	public List<Junction> getItinerary(){
		return copiaItinerario;
		
	}
	public Road getRoad() {
		return road;
	}
	
	

	public int getLocalizacion() {
		return localizacion;
	}
	
	public int getDistance() {
		return distRecorrida;
	}

	public Junction getCruceActual() {
		
		return itinerario.get(siguienteCruce-1);
	}
	public int getContamTotal() {
		return contamTotal;
	}
}
