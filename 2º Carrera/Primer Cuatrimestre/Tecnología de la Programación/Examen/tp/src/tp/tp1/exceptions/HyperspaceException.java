package tp.tp1.exceptions;

public class HyperspaceException extends Exception{

	private String mensaje;
	
	public HyperspaceException() {
		super();
	}
	public HyperspaceException(String message){
		super(message); 
		mensaje = message;
		}
	public HyperspaceException(String message, Throwable cause){
		super(message, cause);
		mensaje = message;
	}
	public HyperspaceException(Throwable cause){
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
