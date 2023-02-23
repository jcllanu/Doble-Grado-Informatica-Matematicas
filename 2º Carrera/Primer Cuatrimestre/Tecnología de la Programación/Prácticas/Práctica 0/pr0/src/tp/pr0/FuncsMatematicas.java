package tp.pr0;

public class FuncsMatematicas {
	public static int factorial (int n) {
		int fact=1;
		if(n>=0) {
			while(n>0) {
				fact=fact*n;
				n--;
			}
		}else {
			fact=0;
		}
		return fact;
	}
	
	public static int combinatorio (int n, int k) {
		int result;
		if (k >= 0 && n >= k) {
			result = factorial(n)/(factorial(k)*factorial(n-k));
		}else {
			result = 0;
		}
		return result;
	}
}