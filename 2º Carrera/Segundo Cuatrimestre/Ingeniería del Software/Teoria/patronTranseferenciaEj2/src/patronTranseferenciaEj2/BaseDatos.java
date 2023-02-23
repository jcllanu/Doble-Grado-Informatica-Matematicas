package patronTranseferenciaEj2;

import java.util.ArrayList;
import java.util.List;

public class BaseDatos {
	private List<Usuario> datosUsuarios;
	
	public BaseDatos (){
		datosUsuarios=new ArrayList<Usuario>();
	}
	
	public List<Usuario> getDatosUsuarios() {
		return datosUsuarios;
	}
}
