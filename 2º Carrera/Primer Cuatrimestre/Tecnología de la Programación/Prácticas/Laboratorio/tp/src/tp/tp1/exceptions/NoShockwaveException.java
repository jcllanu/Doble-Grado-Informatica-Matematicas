package tp.tp1.exceptions;

public class NoShockwaveException extends Exception{
	private String mensaje;
	
	public NoShockwaveException() { 
		super(); 
	}
	public NoShockwaveException(String message){ 
		super(message); 
		mensaje = message;
	}
	public NoShockwaveException(String message, Throwable cause){
		super(message, cause);
		mensaje = message;
	}
	public NoShockwaveException(Throwable cause){ 
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
