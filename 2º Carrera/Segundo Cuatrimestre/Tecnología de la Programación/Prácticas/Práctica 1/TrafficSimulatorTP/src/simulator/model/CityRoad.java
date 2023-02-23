package simulator.model;

public class CityRoad extends Road{

	CityRoad(String id, Junction j1, Junction j2, int n, int m, int l, Weather w) {
		super(id, j1, j2, n, m, l, w);
	}


	@Override
	void updateSpeedLimit() {
		limiteVelActual=velMaxim;
	}

	@Override
	int calculateVehicleSpeed(Vehicle v) {
		int dev;
		
		dev=(int)(((11.0-v.getContClass())/11.0)*limiteVelActual);
		
		return dev;
	}

	@Override
	void reduceTotalContamination() {
		int x=weather.getUnidadesReduccionContCity();
		contaminacionTotal-=x;
		if(contaminacionTotal<0) {
			contaminacionTotal=0;
		}
	}

}
