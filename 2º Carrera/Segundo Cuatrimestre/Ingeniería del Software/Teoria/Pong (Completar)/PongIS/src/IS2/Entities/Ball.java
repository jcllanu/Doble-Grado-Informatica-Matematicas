package IS2.Entities;

import IS2.Math.Geometry.Rectangle;
import IS2.Math.Number.Complex;
import IS2.Pong;

import java.awt.*;
import java.util.concurrent.ThreadLocalRandom;

public class Ball extends Entity {
	
    private static final int DIAMETER = 20, MIN_SPEED = 3, MAX_SPEED = 20;
    private static final double MIN_ANGLE = -0.5, MAX_ANGLE = 0.5;
    private static final int INITIAL_X = (Pong.WIDTH - DIAMETER) / 2, INITIAL_Y = (Pong.HEIGHT - DIAMETER) / 2;
    public static int izq = 0;
    public static int der = 0;
    
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
    	
        Rectangle cb = this.intersects(other);

        if (this.equals(other) || cb == null) return;
      	this.velocity.mirrorY();
      	if(this.velocity.getR() < MAX_SPEED)
      		this.velocity.addMagnitude(1);
      	addRandomAngle();
    }

    private void reset() {
        position.set(INITIAL_X, INITIAL_Y);
        velocity.set(MIN_SPEED * (ThreadLocalRandom.current().nextBoolean() ? -1 : 1), 0);
        addRandomAngle();
    }

    @Override
    public void update() {
        super.update();
        if(this.outOfVerticalBounds()) {
        	this.velocity.mirrorX();
        }
        else if(this.outOfHorizontalBounds()) {
        	if(this.bb.upperLeft().getX() < 0) {
        		der++;
        	}
        	else {
        		izq++;
        	}
        	System.out.println(izq + " - " + der + '\n' + '\n' + '\n' + '\n' + '\n' + '\n');
        	this.reset();
        }
    }
}
