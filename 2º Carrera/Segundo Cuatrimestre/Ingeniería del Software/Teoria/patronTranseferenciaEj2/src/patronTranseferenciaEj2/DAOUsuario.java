package patronTranseferenciaEj2;

public interface DAOUsuario {
	//Interfaz DAO (Data Access Object)
	//CRUD
	
	public void create (UsuarioDTO user);
	public UsuarioDTO read (int id);
	public void update (UsuarioDTO user);
	public void delete (int id);
	
}
