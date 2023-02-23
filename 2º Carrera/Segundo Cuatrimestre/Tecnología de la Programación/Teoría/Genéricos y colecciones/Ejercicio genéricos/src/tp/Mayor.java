package tp;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Iterator;
import java.util.List;

public class Mayor<T extends Comparable<T>> {
	
	
	public static void main(String[] args) {

		Fecha f1= new Fecha(1,2,3);
		Fecha f2= new Fecha(4,5,20);
		Fecha f3= new Fecha(7,8,9);

		List<Fecha> fechas=new ArrayList<Fecha>();
		fechas.add(f1);
		fechas.add(f2);
		fechas.add(f3);
		
		Mayor<Fecha> aux=new Mayor<Fecha>();
		System.out.println(aux.devuelveMayor(fechas));
		System.out.println(" ");
		aux.mostrarArray(fechas);
		System.out.println("_______");
		System.out.println(" ");
		Cliente c1= new Cliente("pepe", 4);
		Cliente c2= new Cliente("pepa", 9);
		Cliente c3= new Cliente("pepo", 62);

		Cliente[] clientes=new Cliente[3];
		clientes[0]=c1;
		clientes[1]=c2;
		clientes[2]=c3;
		
		Mayor<Cliente> aux2=new Mayor<Cliente>();
		System.out.println(aux2.devuelveMayor(clientes));
		System.out.println(" ");
		aux2.mostrarArray(clientes);
		System.out.println("_______");
		System.out.println(" ");
		String s1= new String("Hola");
		String s2= new String("Adiós");
		String s3= new String("Waaaaaaaa");

		String[] strings=new String[3];
		strings[0]=s1;
		strings[1]=s2;
		strings[2]=s3;
		
		Mayor<String> aux3=new Mayor<String>();
		System.out.println(aux3.devuelveMayor(strings));
		System.out.println(" ");
		aux3.mostrarArray(strings);
	}
	
	
	public T devuelveMayor(List<T> array) {
	
		T dato = array.get(0);
		for(T element: array) {
			if(element.compareTo(dato)>=0) {
				dato = element;
			}
		}
		return dato;
		
	}
	
	public void mostrarArray (Collections array) {
		Iterator<Object> it=array.emptyIterator();
			while(it.hasNext())
				System.out.println(it.next());
		
			
	}
}