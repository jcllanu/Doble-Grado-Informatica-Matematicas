package IS2.Entities;

import IS2.Math.Geometry.Rectangle;
import IS2.Math.Number.Complex;
import IS2.Pong;

import java.awt.*;
import java.util.concurrent.ThreadLocalRandom;

public class Ball extends Entity {
    private static final int DIAMETER = 20, MIN_SPEED = 3, MAX_SPEED = 5;
    private static final double MIN_ANGLE = -0.2, MAX_ANGLE = 0.2;
    private static final int INITIAL_X = (Pong.WIDTH - DIAMETER) / 2, INITIAL_Y = (Pong.HEIGHT - DIAMETER) / 2;

    public Ball() {
        super(new Complex(), new Complex(), DIAMETER);
        reset();
    }

    @Override
    public void draw(Graphics graphics, Color color) {
        graphics.setColor(color);
        graphics.fillOval((int) position.getX(), (int) position.getY(), DIAMETER, DIAMETER);
        Toolkit.getDefaultToolkit().sync();
    }

    private void addRandomAngle() {
        velocity.addAngle(ThreadLocalRandom.current().nextDouble(MIN_ANGLE, MAX_ANGLE));
    }

    @Override
    public void collide(Entity other) {
        // Collision box
        Rectangle cb;

        if (this.equals(other) || (cb = this.intersects(other)) == null) return;

        // ...
    }

    private void reset() {
        position.set(INITIAL_X, INITIAL_Y);
        velocity.set(MIN_SPEED * (ThreadLocalRandom.current().nextBoolean() ? -1 : 1), 0);
        addRandomAngle();
    }

    @Override
    public void update() {
        super.update();

        // ...
    }
}
