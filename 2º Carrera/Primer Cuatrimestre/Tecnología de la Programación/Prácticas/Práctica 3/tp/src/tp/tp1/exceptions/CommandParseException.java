package tp.tp1.exceptions;

public class CommandParseException extends Exception{
	private String mensaje;
	
	public CommandParseException() {
		super(); 
	}
	public CommandParseException(String message){
		mensaje = message;
}
	public CommandParseException(String message, Throwable cause){
		super(message, cause);
		mensaje = message; 
	}
	public CommandParseException(Throwable cause){
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
