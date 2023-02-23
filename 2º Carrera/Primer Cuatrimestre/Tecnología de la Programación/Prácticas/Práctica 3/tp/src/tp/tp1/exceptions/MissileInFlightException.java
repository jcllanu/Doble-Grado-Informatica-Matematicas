package tp.tp1.exceptions;

//Según el enunciado habrá que cambiar unas cosas del iplayerontroler
//Lo amarillo que sale ni idea de por qué
//El último  comentado no se que es exactamente
//Habrá qeu poner más cosas obviamente me he limitado a copiar lo de la teoría

public class MissileInFlightException extends Exception{
	
	private String mensaje;
	
	public MissileInFlightException() {
		super();
	}
	public MissileInFlightException(String message){
		super(message); 
		mensaje = message;
		}
	public MissileInFlightException(String message, Throwable cause){
		super(message, cause);
		mensaje = message;
	}
	public MissileInFlightException(Throwable cause){
		super(cause);
		mensaje=cause.getMessage();
	}
	/*Exception(String message, Throwable cause, boolean enableSuppression, boolean writableStackTrace){
		super(message, cause, enableSuppression, writeableStackTrace)
	}*/
	public String getMessage() {
		return mensaje;
	}
}
