package simulator.model;

public enum Weather {
	SUNNY, CLOUDY, RAINY, WINDY, STORM;
	
	public int getPorcentajeReduccionContInterCity() {
		int x = 0;
		if(this==Weather.SUNNY) {
			x=2;
		}else if(this==Weather.CLOUDY) {
			x=3;
		}else if(this==Weather.RAINY) {
			x=10;
		}else if(this==Weather.WINDY) {
			x=15;
		}else if(this==Weather.STORM) {
			x=20;
		}
		return x;
	}
	public int getUnidadesReduccionContCity() {
		int x = 0;
		if(this==Weather.WINDY||this==Weather.STORM) {
			x=10;
		}else{
			x=2;
		}
		return x;
	}
}
