package patronTranseferenciaEj2;


public class Usuario{
	
	private int id;
	private String nombre;
	private String contrasenna;
	private String eMail;
	private boolean activo;
	
	//Constructora 
	
	public Usuario(int id, String nombre, String eMail, boolean activo, String contrasenna)	{
		this.id= id;
		this.nombre= nombre;
		this.eMail= eMail;
		this.activo= activo;
		this.contrasenna=contrasenna;
	}
	
	//Métodos de usuario
	
	public void reservarLibro() {};
	public void renovarLibro() {};
	public void devolverLibro() {};
		
		
	//Getters
	public int getId() {
		return id;
	}

	public String getNombre() {
		return nombre;
	}
	
	public String getEMail() {
		return eMail;
	}
	
	public boolean getActivo() {
		return activo; 
	}
	
	public String getContrasenna() {
		return contrasenna;
	}
	
	//Setters
	public void setId(int id) {
		this.id= id;
	}

	public void setNombre(String nombre) {
		this.nombre= nombre;
	}
	
	public void setEMail(String eMail) {
		this.eMail= eMail;
	}
	
	public void setActivo(boolean activo) {
		this.activo= activo;
	}

	public void setContrasenna(String contrasenna) {
		this.contrasenna=contrasenna;
		
	}

	
	
	
}
