package patronTransferenciaEj1;

public class EstudianteDTO {
		private String nombre;
		private int identificador;
		
		public EstudianteDTO(String nombre, int id) {
			this.nombre=nombre;
			this.identificador=id;
		}
		
		public String getNombre() {
			return nombre;
		}
		
		public void setNombre(String nombre) {
			this.nombre=nombre;
		}
		
		public int getIdentificador() {
			return identificador;
		}
		
		public void setIdentificador(int id) {
			this.identificador=id;
		}
		
}
