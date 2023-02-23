package simulator.factories;

import java.util.LinkedList;
import java.util.List;

import org.json.JSONArray;
import org.json.JSONObject;

import simulator.misc.Pair;
import simulator.model.Event;
import simulator.model.SetContClassEvent;

public class SetContClassEventBuilder extends Builder<Event>{

	public SetContClassEventBuilder() {
		super("set_cont_class");
	}

	@Override
	protected Event createTheInstance(JSONObject data) {
		if(data.has("time")&&data.has("info")) {
			List<Pair<String,Integer>> list = new LinkedList<Pair<String,Integer>>();
			JSONArray ar = data.getJSONArray("info");
			for(int i=0; i<ar.length(); i++) {
				JSONObject ob=ar.getJSONObject(i);
				if(ob.has("vehicle")&&ob.has("class")) {
					list.add(new Pair<String, Integer>(ob.getString("vehicle"),ob.getInt("class")));
				}else {
					throw new IllegalArgumentException("Invalid value for createTheInstance: " + data);
				}
			}
							
		return new SetContClassEvent(data.getInt("time"),list);
			
		}
		else {
			throw new IllegalArgumentException("Invalid value for createTheInstance: " + data);
		}
	}

}
