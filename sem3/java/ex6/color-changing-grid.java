import java.awt.Color;
import java.awt.GridLayout;
import java.util.*;

import javax.swing.*;

public class ColorChangingFrame extends JFrame
{
    /**
         *
         */
        private static final long serialVersionUID = 1L;
        private JPanel north, south, east, west, center;
    private Random rand = new Random();

    public ColorChangingFrame()
    {
        setTitle("Color Changing Panels");
        setBounds(500, 500, 600, 600); // Square to make panels visually equal
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        // Main panel with 3x3 grid
        JPanel mainPanel = new JPanel(new GridLayout(1, 1));
        add(mainPanel);

        // Empty panels for corners
        JPanel empty1 = new JPanel();
        JPanel empty2 = new JPanel();
        JPanel empty3 = new JPanel();
        JPanel empty4 = new JPanel();

        // Create panels
        north = new JPanel();
        south = new JPanel();
        east = new JPanel();
        west = new JPanel();
        center = new JPanel();

        // Add panels in grid order

        mainPanel.add(north);
        mainPanel.add(empty1);

        mainPanel.add(west);
        mainPanel.add(empty2);
        mainPanel.add(center);
        mainPanel.add(empty3);
        mainPanel.add(east);

        mainPanel.add(empty4);


        mainPanel.add(south);


        // Set initial colors
        north.setBackground(Color.BLUE);
        south.setBackground(Color.GREEN);
        east.setBackground(Color.RED);
        west.setBackground(Color.MAGENTA);
        center.setBackground(Color.ORANGE);

        // Timer to change colors
        javax.swing.Timer timer = new javax.swing.Timer(3000, e -> changeColors());
        timer.start();

        setVisible(true);
    }

    private void changeColors()
    {
        north.setBackground(randomColor());
        south.setBackground(randomColor());
        east.setBackground(randomColor());
        west.setBackground(randomColor());
        center.setBackground(randomColor());
    }

    private Color randomColor()
    {
        return new Color(rand.nextInt(256), rand.nextInt(256), rand.nextInt(256));
    }

    public static void main(String[] args)
    {
        SwingUtilities.invokeLater(ColorChangingFrame::new);
    }
}
