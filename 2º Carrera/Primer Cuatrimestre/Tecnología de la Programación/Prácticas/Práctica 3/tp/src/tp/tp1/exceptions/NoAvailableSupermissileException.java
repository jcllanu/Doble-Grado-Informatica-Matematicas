package tp.tp1.exceptions;

public class NoAvailableSupermissileException extends Exception{
	private String mensaje;
	
	public NoAvailableSupermissileException() { super(); }
	public NoAvailableSupermissileException(String message){
		mensaje = message; 
	}
	public NoAvailableSupermissileException(String message, Throwable cause){
		super(message, cause);
		mensaje = message; 
	}
	public NoAvailableSupermissileException(Throwable cause){ 
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
