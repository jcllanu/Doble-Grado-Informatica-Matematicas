package patronTransferenciaEj1;

public class DemoPatronTransferencia {

	public static void main(String[] args) {
		EstudianteDAO estudianteBuisinessObject =new EstudianteDAO();
		
		//Mostrar los estudiantes
		for(EstudianteDTO estudiante: estudianteBuisinessObject.getEstudiantes()) {
			System.out.println("Estudiante: [Identificador: "+estudiante.getIdentificador()+", Nombre: "+estudiante.getNombre()+"]");
		}

		//Actualizar estudiantes
		EstudianteDTO estudiante=estudianteBuisinessObject.getEstudiante(0);
		estudiante.setNombre("Laura");
		if(estudianteBuisinessObject.actualizarEstudiante(estudiante)) {
			System.out.println("Estudiante: Identificador "+estudiante.getIdentificador()+", actualizado en la base de datos");
		}
		else {
			System.out.println("No se ha podido actualizar el estuiante");
		}
		
		//Obtener estudiante
		
		estudiante=estudianteBuisinessObject.getEstudiante(0);
		System.out.println("Estudiante: [Identificador: "+estudiante.getIdentificador()+", Nombre: "+estudiante.getNombre()+"]");
		
		
		//Eliminar estudiante
		
		estudianteBuisinessObject.eliminarEstudiante(estudianteBuisinessObject.getEstudiante(1));
		
		//Mostrar los estudiantes
		for(EstudianteDTO estudi: estudianteBuisinessObject.getEstudiantes()) {
			System.out.println("Estudiante: [Identificador: "+estudi.getIdentificador()+", Nombre: "+estudi.getNombre()+"]");
		}

	}

}
