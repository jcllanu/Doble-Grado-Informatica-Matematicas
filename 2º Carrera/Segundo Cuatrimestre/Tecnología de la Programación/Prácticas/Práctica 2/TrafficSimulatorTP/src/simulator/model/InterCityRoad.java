package simulator.model;

public class InterCityRoad extends Road {

	InterCityRoad(String id, Junction j1, Junction j2, int n, int m, int l, Weather w) {
		super(id, j1, j2, n, m, l, w);
		
	}


	@Override
	void updateSpeedLimit() {
		if(contaminacionTotal>limiteContaminacion) {
			limiteVelActual=(int) (velMaxim*0.5);
		}else {
			limiteVelActual=velMaxim;
		}
	}

	@Override
	int calculateVehicleSpeed(Vehicle v) {
		int dev;
		if(this.weather==Weather.STORM) {
			dev=(int)(0.8*limiteVelActual);
		}else {
			dev=limiteVelActual;
		}
		return dev;
	}

	@Override
	void reduceTotalContamination() {
		int x = weather.getPorcentajeReduccionContInterCity();
		contaminacionTotal=(int)(((100.0-x)/100.0)*contaminacionTotal);
	}

}
