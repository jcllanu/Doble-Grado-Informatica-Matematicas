package tp;

public class Fecha implements Comparable<Fecha> {
	private int dia;
	private int mes;
	private int ano;
	
	public Fecha(int dia, int mes, int anno) {
		this.dia=dia;
		this.mes=mes;
		this.ano=anno;
	}
	public int compareTo(Fecha o) {
		if(this.ano > o.ano || this.ano == o.ano && this.mes > o.mes || this.ano == o.ano && this.mes == o.mes && this.dia>o.dia) {
			return 1;
		}
		else if(this.ano == o.ano && this.mes == o.mes && this.dia==o.dia){
			return 0;
		}else {
			return -1;
		}
	}
	public String toString() {
		return dia+"/"+mes+"/"+ano;
	}
}
