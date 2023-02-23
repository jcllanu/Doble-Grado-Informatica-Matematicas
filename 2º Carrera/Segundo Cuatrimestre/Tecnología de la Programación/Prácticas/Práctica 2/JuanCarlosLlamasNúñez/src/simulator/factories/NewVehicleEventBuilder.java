package simulator.factories;

import java.util.LinkedList;
import java.util.List;

import org.json.JSONArray;
import org.json.JSONObject;

import simulator.model.Event;
import simulator.model.NewVehicleEvent;

public class NewVehicleEventBuilder extends Builder<Event>{
	


	public NewVehicleEventBuilder() {
		super("new_vehicle");
		
	}

	@Override
	protected Event createTheInstance(JSONObject data) {
		Event e;
		
		if(data.has("time")&&data.has("id")&&data.has("maxspeed")&&data.has("class")&&data.has("itinerary")) {
			List<String> list= new LinkedList<String>();
			JSONArray ar = data.getJSONArray("itinerary");
			for(int i=0; i<ar.length(); i++) {
				list.add(ar.getString(i));
			}
							
			e=new NewVehicleEvent(data.getInt("time"),data.getString("id"),data.getInt("maxspeed"),data.getInt("class"),list);
			
		}
		else {
			throw new IllegalArgumentException("Invalid value for createTheInstance: " + data);
		}
		return e;
		
	}
}