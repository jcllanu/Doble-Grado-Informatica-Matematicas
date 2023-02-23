package IS2.Entities;

import IS2.Math.Geometry.Intersectable;
import IS2.Math.Geometry.Rectangle;
import IS2.Math.Geometry.Square;
import IS2.Math.Number.Complex;

public abstract class Entity extends Intersectable<Rectangle> implements Drawable {
    protected Complex position, velocity;

    public abstract void collide(Entity entity);

    public void update() {
        position.add(velocity);
    }
}
