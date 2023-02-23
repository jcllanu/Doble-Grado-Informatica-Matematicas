package simulator.factories;

import org.json.JSONObject;

import simulator.model.LightSwitchingStrategy;
import simulator.model.RotondaStrategy;

public class RotondaStrategyBuilder extends Builder<LightSwitchingStrategy> {

	public RotondaStrategyBuilder() {
		super("ra");
		
	}

	@Override
	protected LightSwitchingStrategy createTheInstance(JSONObject data) {
		return new RotondaStrategy();
	}
}
