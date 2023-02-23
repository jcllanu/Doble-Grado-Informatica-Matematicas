package simulator.model;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

import org.json.JSONArray;
import org.json.JSONObject;

public abstract class Road extends SimulatedObject {

	private int length;
	private Junction src;
	private Junction dest;
	protected Weather weather;
	protected int contaminacionTotal;
	protected int velMaxim;
	protected int limiteVelActual;
	protected int limiteContaminacion;
	private List<Vehicle> vehiculos;//Mantener siempre ordenado de mayor a menor localizacion
	//private List<Vehicle> vehiculosParaDevolver;//copia inmodificable de vehiculos
	//La lista vehiculosParaDevolver de arriba no se usa. Si hubiera que devolver vehiculos se tendría que descomentar y devolver esta
	
	Road(String id, Junction srcJunc, Junction destJunc, int maxSpeed, int contLimit, int length, Weather weather) {
		super(id);
		if(srcJunc==null||destJunc==null||weather==null||maxSpeed<=0||contLimit<0||length<=0) {
			throw new IllegalArgumentException("srcJunc, destJunc, weather, maxSpeed, contLimit y length deben ser argumentos válidos");
		}
		vehiculos=new ArrayList<Vehicle>();
		//vehiculosParaDevolver=Collections.unmodifiableList(vehiculos);
		src=srcJunc;
		dest=destJunc;
		this.length=length;
		this.weather=weather;
		velMaxim=maxSpeed;
		limiteContaminacion=contLimit;
		src.addOutGoingRoad(this);
		dest.addIncommingRoad(this);
	}

	@Override
	void advance(int time) {
		reduceTotalContamination();
		updateSpeedLimit();
		for(Vehicle v:vehiculos) {
			v.setSpeed(calculateVehicleSpeed(v));
			v.advance(time);
		}
		
		//Collections.sort(vehiculos);
		
		Collections.sort(vehiculos, new Comparator<Vehicle>() {
			public int compare(Vehicle v1, Vehicle v2) {
				return v2.getLocalizacion()-v1.getLocalizacion();
			}});
	}

	

	@Override
	public JSONObject report() {
		JSONObject j = new JSONObject();
		
		j.put("id", _id);
		j.put("speedlimit", limiteVelActual);
		j.put("weather", weather);
		j.put("co2", contaminacionTotal);
		JSONArray arr = new JSONArray();
		for(Vehicle v:vehiculos) {
			arr.put(v._id);
		}
		j.put("vehicles", arr);
		
		return j;
	}

	public int getLength() {
		return length;
	}

	public Junction getSrc() {
		return src;
	}

	public Junction getDest() {
		return dest;
	}

	void setWeather(Weather w) {
		if(w!=null) {
			this.weather = w;
		}else {
			throw new IllegalArgumentException("Weather debe ser distinto de null");
		}
	}
	
	void addContamination (int cont){
		if(cont >=0) {
			contaminacionTotal+=cont;
		}else {
			throw new IllegalArgumentException("La contaminación a añadir debe ser no negativa");
		}
		
	}
	
	void enter (Vehicle v) {
		if(v.getSpeed()!=0 || v.getLocalizacion()!=0) {
			throw new IllegalArgumentException("Para que un vehiculo entre en una carretera debe estar en la localizacion ero con velocidad cero");
		}else {
			vehiculos.add(v);
		}
	}
	
	void exit (Vehicle v) {
		vehiculos.remove(v);
	}
	
	abstract void reduceTotalContamination();
	abstract void updateSpeedLimit();
	abstract int calculateVehicleSpeed(Vehicle v);

	public int getTotalCO2() {
		return contaminacionTotal;
	}

	public int getCO2Limit() {
		return limiteContaminacion;
	}
	public int getMaxSpeed() {
		return velMaxim;
	}
	public int getSpeedLimit() {
		return limiteVelActual;
	}
	public Weather getWeather() {
		return weather;
	}
	public List<Vehicle> getVehicles() {
		 return Collections.unmodifiableList(vehiculos);
	}
}
