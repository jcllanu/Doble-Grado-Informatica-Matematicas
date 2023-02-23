package tp.tp1.exceptions;

public class WarmUpEngineException extends Exception{

	private String mensaje;
	
	public WarmUpEngineException() {
		super();
	}
	public WarmUpEngineException(String message){
		super(message); 
		mensaje = message;
		}
	public WarmUpEngineException(String message, Throwable cause){
		super(message, cause);
		mensaje = message;
	}
	public WarmUpEngineException(Throwable cause){
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
