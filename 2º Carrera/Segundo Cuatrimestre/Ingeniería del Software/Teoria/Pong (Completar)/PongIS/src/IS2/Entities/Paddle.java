package IS2.Entities;

import IS2.Math.Number.Complex;
import IS2.Pong;

import java.awt.*;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;

public class Paddle extends Entity implements KeyListener {
	
    public static final int WIDTH = 20, HEIGHT = 80;
    private PaddleSide side;
    
    public Paddle(PaddleSide p) {
    	super(p.initialPosition, new Complex(0,0), WIDTH, HEIGHT);
    	this.side = p;
    }

    @Override
    public void draw(Graphics graphics, Color color) {
        graphics.setColor(color);
        graphics.fillRect((int) position.getX(), (int) position.getY(), WIDTH, HEIGHT);
        Toolkit.getDefaultToolkit().sync();
    }

    @Override
    public void collide(Entity entity) {
        // NOP
    }

    @Override
    public void keyTyped(KeyEvent keyEvent) {
        // NOP
    }

    public void keyPressed(KeyEvent keyEvent) {
        if (keyEvent.getKeyCode() == side.upKey) {
            velocity.setY(-7);
        } else if (keyEvent.getKeyCode() == side.downKey) {
            velocity.setY(7);
        }
    }

    public void keyReleased(KeyEvent keyEvent) {
        if (keyEvent.getKeyCode() == side.upKey || keyEvent.getKeyCode() == side.downKey)
            velocity.setR(0);
    }

    @Override
    public void update() {
        super.update();
        if(this.outOfVerticalBounds()) {
        	Complex v = new Complex(velocity.getX(), - velocity.getY());
        	position.add(v);
        }
    }
}
