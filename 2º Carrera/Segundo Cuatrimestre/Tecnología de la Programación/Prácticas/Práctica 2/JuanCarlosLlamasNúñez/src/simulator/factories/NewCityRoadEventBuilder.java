package simulator.factories;

import simulator.model.Event;
import simulator.model.NewCityRoadEvent;
import simulator.model.Weather;

public class NewCityRoadEventBuilder extends NewRoadEventBuilder{

	public NewCityRoadEventBuilder() {
		super("new_city_road");
	
	}

	@Override
	Event createTheRoad() {
		
		return new NewCityRoadEvent(time, id, source, dest, length, co2limit, maxSpeed, Weather.valueOf(weather));
	}

}
