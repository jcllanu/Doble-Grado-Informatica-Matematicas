package tp;


	public class Cliente implements Comparable<Cliente> {
		private String nombre;
		private int edad;
		
		public Cliente(String nombre, int edad) {
			this.nombre=nombre;
			this.edad=edad;
			
		}
		
		public int compareTo(Cliente o) {
			if(this.edad>o.edad) {
				return 1;
			}
			else if(this.edad==o.edad){
				return 0;
			}else {
				return -1;
			}
		}
		public String toString() {
			return "Nombre: "+nombre+" Edad: "+edad;
		}
	}


