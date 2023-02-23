package tp.tp1.exceptions;

public class NotEnoughPointsException extends Exception{
private String mensaje;
	
	
	public NotEnoughPointsException() { super(); }
	public NotEnoughPointsException(String message){ 
		super(message);
		mensaje = message; 
	}
	public NotEnoughPointsException(String message, Throwable cause){
		super(message, cause);
		mensaje = message;
	}
	public NotEnoughPointsException(Throwable cause){ 
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
