package patronTranseferenciaEj2;

public class DAOUsuarioImp implements DAOUsuario{
	//Clase de negocio
	
	//Esta clase es la encargada de interactuar con la base de datos
	BaseDatos baseDatos;
	public DAOUsuarioImp() {
		baseDatos=new BaseDatos();
	}
	public UsuarioDTO read (int id) {
		
		//Código acceso a la base de datos
		Usuario user=baseDatos.getDatosUsuarios().get(id);
		
		//Devolvemos un objeto de solo lectura(sin acceso a la contraseña
		UsuarioDTO usuario= new UsuarioDTO(user.getId(),user.getNombre(),user.getEMail(),user.getActivo());

		return usuario;
	}

	@Override
	public void create(UsuarioDTO user) {
		Usuario usuario=new Usuario(user.getId(), user.getNombre(), user.getEMail(), user.getActivo(),"1234");
		baseDatos.getDatosUsuarios().add(usuario);
	}

	@Override
	public void update(UsuarioDTO user) {
		Usuario usuario=baseDatos.getDatosUsuarios().get(user.getId());
		usuario.setActivo(user.getActivo());
		usuario.setEMail(user.getEMail());
		usuario.setNombre(user.getNombre());
	}

	@Override
	public void delete(int i) {
		baseDatos.getDatosUsuarios().remove(i);
	}
}
