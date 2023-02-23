package simulator.model;

import java.util.List;

import org.json.JSONArray;
import org.json.JSONObject;

public class CruceConRotonda extends Junction{

	CruceConRotonda(String id, int xCoor, int yCoor) {
		super(id, new RotondaStrategy(), new MoveFirstStrategy() , xCoor, yCoor);
	}
}
