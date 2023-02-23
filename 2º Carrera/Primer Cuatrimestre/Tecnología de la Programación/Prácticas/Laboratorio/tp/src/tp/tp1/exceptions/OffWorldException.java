package tp.tp1.exceptions;

public class OffWorldException extends Exception{
	private String mensaje;
	
	public OffWorldException() { 
		super();
	}
	public OffWorldException(String message){ 
		super(message);
		mensaje = message;
	}
	public OffWorldException(String message, Throwable cause){
		super(message, cause);
		mensaje = message;
	}
	public OffWorldException(Throwable cause){ 
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
