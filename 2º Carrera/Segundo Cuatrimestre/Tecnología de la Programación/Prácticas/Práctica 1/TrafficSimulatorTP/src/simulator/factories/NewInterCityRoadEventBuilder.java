package simulator.factories;

import simulator.model.Event;
import simulator.model.NewInterCityRoadEvent;
import simulator.model.Weather;

public class NewInterCityRoadEventBuilder extends NewRoadEventBuilder{

	public NewInterCityRoadEventBuilder() {
		super("new_inter_city_road");

	}

	
	Event createTheRoad() {
		return new NewInterCityRoadEvent(time, id, source, dest, length, co2limit, maxSpeed, Weather.valueOf(weather));
	}
}
