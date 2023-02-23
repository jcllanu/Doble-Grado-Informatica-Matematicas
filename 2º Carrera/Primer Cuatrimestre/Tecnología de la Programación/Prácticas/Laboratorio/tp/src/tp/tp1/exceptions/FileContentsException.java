package tp.tp1.exceptions;

public class FileContentsException extends Exception{
	private String mensaje;
	
	
	public FileContentsException() {
		super(); 
	}
	public FileContentsException(String message){
		super(message);
		mensaje = message; 
	}
	public FileContentsException(String message, Throwable cause){
		super(message, cause);
		mensaje = message+cause.getMessage();
	}
	public FileContentsException(Throwable cause){ 
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
