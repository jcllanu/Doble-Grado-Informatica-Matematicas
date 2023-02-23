package IS2;

import IS2.Entities.Ball;
import IS2.Entities.Entity;
import IS2.Entities.Paddle;
import IS2.Entities.PaddleSide;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Set;

class PongPanel extends JPanel implements ActionListener {
    private final Ball ball = new Ball();
    private final Paddle leftPaddle = new Paddle(PaddleSide.LEFT), rightPaddle = new Paddle(PaddleSide.RIGHT);
    private final Set<Entity> objects = Set.of(ball, leftPaddle, rightPaddle);

    PongPanel() {
        setPreferredSize(new Dimension(Pong.WIDTH, Pong.HEIGHT));
        setBackground(Color.BLACK);
        setFocusable(true);
        setDoubleBuffered(true);

        addKeyListener(leftPaddle);
        addKeyListener(rightPaddle);

        new Timer(10, this).start();
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        checkCollisions();
        objects.forEach(Entity::update);
        repaint();
    }

    private void checkCollisions() {
        ball.collide(leftPaddle);
        ball.collide(rightPaddle);
    }

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        objects.forEach(e -> e.draw(g, Color.WHITE));
    }
}