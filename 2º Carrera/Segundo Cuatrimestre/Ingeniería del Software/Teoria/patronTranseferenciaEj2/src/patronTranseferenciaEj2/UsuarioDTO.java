package patronTranseferenciaEj2;

import java.io.Serializable;

@SuppressWarnings("serial")





public class UsuarioDTO implements Serializable{
	//DTO (Data Transfer Object)
	
	private int id;
	private String nombre;
	private String eMail;
	private boolean activo;

	//Constructoras 
	public UsuarioDTO(String nombre, String eMail) {
		this.id=0;
		this.nombre= nombre;
		this.eMail= eMail;
		this.activo= true;
	}

	
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
	
	//Serializar
	
	public JSONObject serializar() {
		JSONObject ob=new JSONObject();
		
		ob.put("nombre",nombre);
		ob.put("id",id);
		ob.put("email",eMail);
		ob.put("activo",activo);
		
		return ob;
	}
	//...
	public UsuarioDTO(int id, String nombre, String eMail, boolean activo)	{
		this.id= id;
		this.nombre= nombre;
		this.eMail= eMail;
		this.activo= activo;
	}
	
	public UsuarioDTO(Usuario u)	{
		this.id= u.getId();
		this.nombre= u.getNombre();
		this.eMail= u.getEMail();
		this.activo= u.getActivo();
	}
	
	
}
