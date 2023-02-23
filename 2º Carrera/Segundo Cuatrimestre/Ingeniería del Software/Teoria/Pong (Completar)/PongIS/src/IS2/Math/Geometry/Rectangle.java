package IS2.Math.Geometry;

import IS2.Math.Number.*;

public class Rectangle {
	
	public double width;
	public double height;
	private Complex c;
	
	public Rectangle(Complex c, double w, double h) {
		this.width = w;
		this.height = h;
		this.c = c;
	}

	public Complex upperLeft() {
		return c;
	}
	
	public Complex lowerRight() {
		Complex k = new Complex(c.getX(), c.getY());
		k.add(new Complex(width,height));
		return k;
	}
	
	public double getWidth() {
		return this.width;
	}
	
	public double getHeight(){
		return this.height;
	}
	
	

}
