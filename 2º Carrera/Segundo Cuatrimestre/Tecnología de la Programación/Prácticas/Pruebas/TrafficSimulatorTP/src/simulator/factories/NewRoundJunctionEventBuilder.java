package simulator.factories;

import org.json.JSONArray;
import org.json.JSONObject;

import simulator.model.DequeuingStrategy;
import simulator.model.Event;
import simulator.model.LightSwitchingStrategy;
import simulator.model.NewJunctionEvent;
import simulator.model.NewRoundJunctionEvent;
import simulator.model.RoadMap;

public class NewRoundJunctionEventBuilder extends Builder<Event>{

	public NewRoundJunctionEventBuilder() {
		super("ra");
	}

	@Override
	protected Event createTheInstance(JSONObject data) {
		Event e;
		if(data.has("time")&&data.has("id")&&data.has("coor")) {
			JSONArray a =data.getJSONArray("coor");
			e=new NewRoundJunctionEvent(data.getInt("time"),data.getString("id"),a.getInt(0),a.getInt(1));
		}
		else {
			throw new IllegalArgumentException("Invalid value for createTheInstance: " + data);
		}
		return e;
	}

}
