package tp.tp1.exceptions;

public class CommandExecuteException extends Exception{
	private String mensaje;
	
	
	public CommandExecuteException() {
		super(); 
	}
	public CommandExecuteException(String message){
		super(message);
		mensaje = message; 
	}
	public CommandExecuteException(String message, Throwable cause){
		super(message, cause);
		mensaje = message+cause.getMessage();
	}
	public CommandExecuteException(Throwable cause){ 
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
