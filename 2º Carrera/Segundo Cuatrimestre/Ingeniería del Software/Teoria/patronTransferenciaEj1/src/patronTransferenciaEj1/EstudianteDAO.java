package patronTransferenciaEj1;

import java.util.ArrayList;
import java.util.List;

public class EstudianteDAO{
	List<EstudianteDTO> estudiantes;
	
	public EstudianteDAO() {
		estudiantes=new ArrayList<EstudianteDTO>();
		EstudianteDTO estudiante1 = new EstudianteDTO("Carmen",0);
		EstudianteDTO estudiante2 = new EstudianteDTO("Luis",1);
		estudiantes.add(estudiante1);
		estudiantes.add(estudiante2);
	}
	
	public boolean eliminarEstudiante(EstudianteDTO estudiante) {
		return estudiantes.remove(estudiante.getIdentificador())!=null;
	}
	
	public List<EstudianteDTO> getEstudiantes(){
		return estudiantes;
	}
	
	public EstudianteDTO getEstudiante(int identificador){
		return estudiantes.get(identificador);
	}
	
	public boolean actualizarEstudiante(EstudianteDTO estudiante) {
		if(estudiante.getIdentificador()>=0 && estudiante.getIdentificador()<estudiantes.size()) {
			estudiantes.get(estudiante.getIdentificador()).setNombre(estudiante.getNombre());
			return true;
		}else {
			return false;
		}
	}
	
}
