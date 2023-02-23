package simulator.factories;

import org.json.JSONObject;

import simulator.model.Event;


public abstract class NewRoadEventBuilder extends Builder<Event>{
	protected int time;
	protected String id;
	protected String source;
	protected String dest;
	protected int length;
	protected int co2limit;
	protected int maxSpeed;
	protected String weather;
	
	NewRoadEventBuilder(String type) {
		super(type);
	}

	@Override
	protected Event createTheInstance(JSONObject data) {
		if(data.has("time")&&data.has("id")&&data.has("src")&&data.has("dest")&&data.has("length")&&data.has("co2limit")&&data.has("maxspeed")&&data.has("weather")){
			time=data.getInt("time");
			id=data.getString("id");
			source=data.getString("src");
			dest=data.getString("dest");
			length=data.getInt("length");
			co2limit=data.getInt("co2limit");
			maxSpeed=data.getInt("maxspeed");
			weather=data.getString("weather");
			
		}else{
			throw new IllegalArgumentException("Invalid value for createTheInstance: " + data);
		}
		return createTheRoad();
	}
	
	abstract Event createTheRoad();
}
