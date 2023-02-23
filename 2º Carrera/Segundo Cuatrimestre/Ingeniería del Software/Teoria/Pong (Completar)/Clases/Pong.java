package IS2;

import javax.swing.*;

public class Pong extends JFrame {
    public static final int HEIGHT = 600;
    public static final int WIDTH = 800;

    private Pong() {
        JFrame frame = new JFrame("Pong");
        frame.add(new PongPanel());
        frame.pack();
        frame.setResizable(false);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(Pong::new);
    }
}
