package simulator.factories;

import org.json.JSONArray;
import org.json.JSONObject;

import simulator.model.DequeuingStrategy;
import simulator.model.Event;
import simulator.model.LightSwitchingStrategy;
import simulator.model.NewJunctionEvent;

public class NewJunctionEventBuilder extends Builder<Event>{
	private Factory<LightSwitchingStrategy> factoriaSemaforos;
	private Factory<DequeuingStrategy> factoriaColas;
	public NewJunctionEventBuilder(Factory<LightSwitchingStrategy> f1, Factory<DequeuingStrategy> f2) {
		super("new_junction");
		factoriaSemaforos=f1;
		factoriaColas=f2;
	}

	@Override
	protected Event createTheInstance(JSONObject data) {
		LightSwitchingStrategy lss = null;
		DequeuingStrategy dqs = null;
		Event e;
		if(data.has("time")&&data.has("id")&&data.has("coor")&&data.has("ls_strategy")&&data.has("dq_strategy")) {
			JSONObject ls = data.getJSONObject("ls_strategy");
			JSONObject dq = data.getJSONObject("dq_strategy");
			JSONArray a =data.getJSONArray("coor");
			
			lss=factoriaSemaforos.createInstance(ls);
			dqs=factoriaColas.createInstance(dq);
			
			e=new NewJunctionEvent(data.getInt("time"),data.getString("id"),lss,dqs,a.getInt(0),a.getInt(1));
		}
		else {
			throw new IllegalArgumentException("Invalid value for createTheInstance: " + data);
		}
		return e;
	}

}
