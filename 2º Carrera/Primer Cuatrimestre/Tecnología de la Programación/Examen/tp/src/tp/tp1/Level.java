package tp.tp1;

public enum Level {
	EASY,HARD,INSANE;
	
	
	
	public double getFrecuenciaDisp() {
		double frec;
		if(this==EASY) {
			frec=0.1;
		}else if(this==HARD) {
			frec=0.3;
		}else {
			frec=0.5;
		}
		return frec;
	}
	public double getFrecuenciaOvni() {
		double frec;
		if(this==EASY) {
			frec=0.5;
		}else if(this==HARD) {
			frec=0.2;
		}else {
			frec=0.1;
		}
		return frec;
	}
	public int getVelocidad() {
		int velocidad;
		if(this==EASY) {
			velocidad=3;
		}else if(this==HARD) {
			velocidad=2;
		}else {
			velocidad=1;
		}
		return velocidad;
	}
	public int getDestroyers() {
		int destroy;
		if(this==EASY) {
			destroy=2;
		}else if(this==HARD) {
			destroy=2;
		}else {
			destroy=4;
		}
		return destroy;
	}
	public int getRegular() {
		int regular;
		if(this==EASY) {
			regular=4;
		}else if(this==HARD) {
			regular=8;
		}else {
			regular=8;
		}
		return regular;
	}
	public int filDestroyer() {
		int fil;
		if(this==EASY) {
			fil=2;
		}else {
			fil=3;
		}
		return fil;
	}
	public int colFirstDestroyer() {
		int col;
		if(this==INSANE) {
			col=3;
		}else {
			col=4;
		}
		return col;
	}
	public static Level parse(String string) {
		if(string.equalsIgnoreCase("easy")) {
			return EASY;
		}else if(string.equalsIgnoreCase("hard")) {
			return HARD;
		}else if(string.equalsIgnoreCase("insane")) {
			return INSANE;
		}else {
			return null;
		}
	}
	public int getBarriers() {
		int barriers;
		if(this==EASY) {
			barriers=4;
		}else if(this==HARD) {
			barriers=3;
		}else {
			barriers=2;
		}
		return barriers;
	}
	public int getSeparacionBarriers() {
		int sep;
		if(this==EASY) {
			sep=2;
		}else if(this==HARD) {
			sep=3;
		}else {
			sep=4;
		}
		return sep;
	}
	public int getcolPrimBarriers() {
		int col;
		if(this==EASY) {
			col=1;
		}else if(this==HARD) {
			col=1;
		}else {
			col=2;
		}
		return col;
	}
}
