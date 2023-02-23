package simulator.factories;

import org.json.JSONObject;

import simulator.model.LightSwitchingStrategy;
import simulator.model.RoundRobinStrategy;

public class MostCrowdedStrategyBuilder extends Builder<LightSwitchingStrategy>{
	public MostCrowdedStrategyBuilder() {
		super("most_crowded_lss");
		
	}
	
	@Override
	protected LightSwitchingStrategy createTheInstance(JSONObject data) {
		if(data.has("timeslot")){
			return new RoundRobinStrategy(data.getInt("timeslot"));
		}else{
			return new RoundRobinStrategy(1);
		}
	}

}
