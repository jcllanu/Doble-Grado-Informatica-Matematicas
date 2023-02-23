package patronTranseferenciaEj2;


public class DemoPatronTransferencia2 {

	public static void main(String[] args) {
		DAOUsuario daoUsuario =new DAOUsuarioImp();
		
		
		//Introducir un nuevos usuarios
		UsuarioDTO userVO1= new UsuarioDTO(0, "Felipe", "felipe@ucm.es", true);
		UsuarioDTO userVO2= new UsuarioDTO(1, "Mónica", "monica@ucm.es", false);
		UsuarioDTO userVO3= new UsuarioDTO("Miguel", "miguel@ucm.es");
		userVO3.setActivo(true);
		userVO3.setId(2);
		
		daoUsuario.create(userVO1);
		daoUsuario.create(userVO2);
		daoUsuario.create(userVO3);

		
		//Actualizar usuarios
		UsuarioDTO userActualizadoVO= new UsuarioDTO(1, "Mónica", "monica2000@ucm.es", true);
		daoUsuario.update(userActualizadoVO);
		
		//Obtener usuario
		UsuarioDTO usuarioVO=daoUsuario.read(0);
		System.out.println("Usuario: ");
		System.out.println("Nombre: "+usuarioVO.getNombre()+"  Email: "+usuarioVO.getEMail()+
				"  ID: "+usuarioVO.getId());
		
		//Eliminar usuario
		daoUsuario.delete(2);
	}
}
