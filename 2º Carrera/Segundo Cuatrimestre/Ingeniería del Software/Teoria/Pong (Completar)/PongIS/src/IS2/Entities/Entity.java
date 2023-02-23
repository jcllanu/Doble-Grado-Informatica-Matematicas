package IS2.Entities;

import IS2.Math.Geometry.Intersectable;
import IS2.Math.Geometry.Rectangle;
import IS2.Math.Geometry.Square;
import IS2.Math.Number.Complex;

public abstract class Entity extends Intersectable<Rectangle> implements Drawable {

	public Entity(Complex position, Complex velocity, int t) {
		super(new Square(position, t));
		this.position = position;
		this.velocity = velocity;
	}
	
	public Entity(Complex position, Complex velocity, int width, int height) {
		super(new Rectangle(position, width, height));
		this.position = position;
		this.velocity = velocity;
	}

	protected Complex position, velocity;

    public abstract void collide(Entity entity);

    public void update() {
        position.add(velocity);
    }
}
