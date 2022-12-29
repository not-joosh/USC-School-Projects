import java.awt.BasicStroke;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.MouseMotionAdapter;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;

import javax.imageio.ImageIO;
import javax.swing.JButton;
import javax.swing.JColorChooser;
import javax.swing.JFileChooser;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JSlider;
import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;

// Line Class
class Line {
	// Attributes
    protected int x1;
    protected int y1;
    protected int x2;
    protected int y2;
    protected Color color;
    protected int thickness;
    
    // Constructor
    Line(int x1, int y1, int x2, int y2, Color color, int thickness) {
		this.x1 = x1;
		this.y1 = y1;
		this.x2 = x2;
		this.y2 = y2;
		this.color = color;
		this.thickness = thickness;
    }
}
class DrawingPanel extends JPanel {
    // Attributes
    protected java.util.List<Line> lines = new java.util.ArrayList<Line>();
    protected Color drawingColor = Color.BLACK;
    protected int lineThickness = 3;
    protected BufferedImage buffer;
    
    // Constructor for the Panel
    DrawingPanel() {
        // Add mouse listeners to allow drawing
        addMouseListener(new MouseAdapter() {
            public void mousePressed(MouseEvent e) {
                lines.add(new Line(e.getX(), e.getY(), e.getX(), e.getY(), getDrawingColor(), getLineThickness()));
  
            }
        });
        
        /*
         * EXPERIMENTAL 
         */
        
        addMouseMotionListener(new MouseMotionAdapter() {
            public void mouseDragged(MouseEvent e) {
                Line line = lines.get(lines.size() - 1);
                int x1 = line.x1;
                int y1 = line.y1;
                int x2 = e.getX();
                int y2 = e.getY();
                int dx = Math.abs(x2 - x1);
                int dy = Math.abs(y2 - y1);
                int sx = x1 < x2 ? 1 : -1;
                int sy = y1 < y2 ? 1 : -1;
                int err = dx - dy;

                while (x1 != x2 || y1 != y2) {
                    int e2 = err * 2;
                    if (e2 > -dy) {
                        err -= dy;
                        x1 += sx;
                    }
                    if (e2 < dx) {
                        err += dx;
                        y1 += sy;
                    }
                    lines.add(new Line(x1, y1, x1, y1, getDrawingColor(), getLineThickness()));
                }
                repaint();
            }
        });
        
        // Add a color chooser button
        JButton colorButton = new JButton("Color");
        colorButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                Color color = JColorChooser.showDialog(DrawingPanel.this, "Choose a color", getDrawingColor());
                if (color != null) {
                    setDrawingColor(color);
                }
            }
        });
        add(colorButton);

        // Add a line thickness slider
        JSlider thicknessSlider = new JSlider(1, 10, getLineThickness());
        thicknessSlider.addChangeListener(new ChangeListener() {
            public void stateChanged(ChangeEvent e) {
                setLineThickness(thicknessSlider.getValue());
            }
        });
        add(thicknessSlider);

        // Add an erase button
        JButton eraseButton = new JButton("Erase");
        eraseButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
            	if (!lines.isEmpty()) {
            	    lines.remove(lines.size() - 1);
            	    updateBuffer();
            	    repaint();
            	}
            }
        });
        
        add(eraseButton);

        // Add a save button
        JButton saveButton = new JButton("Save");
        saveButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                JFileChooser fileChooser = new JFileChooser();
                if (fileChooser.showSaveDialog(DrawingPanel.this) == JFileChooser.APPROVE_OPTION) {
                    File file = fileChooser.getSelectedFile();
                    try {
                        BufferedImage image = new BufferedImage(getWidth(), getHeight(), BufferedImage.TYPE_INT_RGB);
                        Graphics2D g2d = image.createGraphics();
                        paint(g2d);
                        ImageIO.write(image, "png", file);
                    } catch (IOException ex) {
                        ex.printStackTrace();
                    }
                }
            }
        });
        add(saveButton);
        
        JButton clearButton = new JButton("Clear");
        clearButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                lines.clear();
                repaint();
            }
        });
        add(clearButton);
    }
    // Method to set the color for new lines
    public void setDrawingColor(Color color) {
        this.drawingColor = color;
    }

    // Method to get the color for new lines
    public Color getDrawingColor() {
        return drawingColor;
    }

    // Method to set the thickness of new lines
    public void setLineThickness(int thickness) {
        this.lineThickness = thickness;
    }

    // Method to get the thickness of new lines
    public int getLineThickness() {
        return lineThickness;
    }

    // Override the paintComponent method to draw the lines
    public void paintComponent(Graphics g) {
        super.paintComponent(g);
        Graphics2D g2d = (Graphics2D) g;
        g2d.setStroke(new BasicStroke(3));
        for (Line line : lines) {
            g2d.setColor(line.color);
            g2d.setStroke(new BasicStroke(line.thickness));
            g2d.drawLine(line.x1, line.y1, line.x2, line.y2);
        }
    }
    /*
     * Experimental DOUBLE BUFFER 
     */
    protected void updateBuffer() {
        // Clear the buffer image
        Graphics2D g2d = buffer.createGraphics();
        g2d.setColor(getBackground());
        g2d.fillRect(0, 0, getWidth(), getHeight());

        // Draw the lines to the buffer image
        g2d.setStroke(new BasicStroke(lineThickness));
        for (Line line : lines) {
            g2d.setColor(line.color);
            g2d.drawLine(line.x1, line.y1, line.x2, line.y2);
        }

        // Dispose of the graphics context
        g2d.dispose();
    }
}
class DrawingGUI extends JFrame {
    // Constructor for the main program class
	 DrawingGUI() {
	        setTitle("Moe Changed");
	        setSize(500, 500);
	        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

	        // Add the drawing panel to the frame
	        DrawingPanel drawingPanel = new DrawingPanel();
	        add(drawingPanel);
	    }
}

public class Main {
	public static void trial1() {
		try {
			DrawingGUI program = new DrawingGUI();
			program.setVisible(true);
		} catch(Exception x) {
			System.out.println(x);
		}
	}
	public static void main(String[] args) {
		trial1();
	}
}
