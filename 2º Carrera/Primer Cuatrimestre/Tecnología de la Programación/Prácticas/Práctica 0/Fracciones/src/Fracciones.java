
public class Fracciones {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Fracciones f1 = new Fracciones(16,10);
		Fracciones f2 = new Fracciones(5,3);
		System.out.println(f1.getNum() + "/" +f1.getDen());
		f2.productoEscalar(6);
		System.out.println(f2.getNum() + "/" +f2.getDen());
		f1.multiplicar(f2);
		System.out.println(f1.getNum() + "/" +f1.getDen());
	}
	
	public Fracciones(int num, int den) {
		this.num = num;
		if (den != 0) {
			this.den = den;
		}else {
			this.den = 1;
		}
		this.simplificar();
	}
	public void productoEscalar(int n) {
		this.num*=n;
		this.simplificar();
	}
	void simplificar() {
		int mcde;
		if(this.num != 0) {
			mcde=mcd(this.num, this.den);
			this.num = this.num/ mcde;
			this.den = this.den/ mcde;
		}
	}
	static int mcd(int a, int b) {
		int maxcomdiv;
		if(b == 0) {
			maxcomdiv=a;
		}else {
			maxcomdiv=mcd(b, a%b);
		}
		return maxcomdiv;
	}
	
	void multiplicar(Fracciones f2) {
		this.num *= f2.num;
		this.den *= f2.den;
		this.simplificar();
	}
	
	public int getNum(){
		return this.num;
	}
	public int getDen(){
		return this.den;
	}
	
	private int num;
	private int den;
}
