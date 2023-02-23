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
	
}
