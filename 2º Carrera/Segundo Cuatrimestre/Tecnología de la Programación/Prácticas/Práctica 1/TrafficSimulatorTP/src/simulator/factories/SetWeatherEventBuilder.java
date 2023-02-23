package simulator.factories;

import java.util.LinkedList;
import java.util.List;

import org.json.JSONArray;
import org.json.JSONObject;

import simulator.misc.Pair;
import simulator.model.Event;
import simulator.model.SetWeatherEvent;
import simulator.model.Weather;

public class SetWeatherEventBuilder extends Builder<Event>{

	public SetWeatherEventBuilder() {
		super("set_weather");
	
	}

	@Override
	protected Event createTheInstance(JSONObject data) {
		if(data.has("time")&&data.has("info")) {
			List<Pair<String,Weather>> ws = new LinkedList<Pair<String,Weather>>();
			JSONArray ar = data.getJSONArray("info");
			for(int i=0; i<ar.length(); i++) {
				JSONObject ob=ar.getJSONObject(i);
				if(ob.has("road")&&ob.has("weather")) {
					ws.add(new Pair<String, Weather>(ob.getString("road"),Weather.valueOf(ob.getString("weather"))));
				}else {
					throw new IllegalArgumentException("Invalid value for createTheInstance: " + data);
				}
			}
							
		return new SetWeatherEvent(data.getInt("time"),ws);
			
		}
		else {
			throw new IllegalArgumentException("Invalid value for createTheInstance: " + data);
		}

	}

}
