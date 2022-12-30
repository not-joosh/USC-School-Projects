import java.awt.BorderLayout;
import java.util.Random;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.RenderingHints;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;
import java.util.List;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JTextField;

class RedBlackTree {
	// Attributes
    static final boolean RED = true;
    private static final boolean BLACK = false;
    private List<String> rotations;  
    private Node root;
    // Mandatory Class
    class Node {
        protected int key;
        protected Node left;
        protected Node right;
        protected boolean color;
        Node(int key) {
            this.key = key;
            this.color = RED;
        }
    }
    // Constructors
    RedBlackTree() {
    	rotations = new ArrayList<>();
    }
    // Methods
    public Node search(int key) { return search(root, key); }
    private Node search(Node node, int key) {
        if (node == null) {
            return null;
        }
        if (key == node.key) {
            return node;
        }
        if (key < node.key) {
            return search(node.left, key);
        } else {
            return search(node.right, key);
        }
    }
    public void insert(int key) {
        root = insert(root, key);
        root.color = BLACK;
    }
    private Node insert(Node node, int key) {
        if (node == null) {
            return new Node(key);
        }
        if (key < node.key) {
            node.left = insert(node.left, key);
        } else {
            node.right = insert(node.right, key);
        }
        if (isRed(node.right) && !isRed(node.left)) {
            node = rotateLeft(node);
        }
        if (isRed(node.left) && isRed(node.left.left)) {
            node = rotateRight(node);
        }
        if (isRed(node.left) && isRed(node.right)) {
            flipColors(node);
        }
        return node;
    }
    private boolean isRed(Node node) {
        if (node == null) {
            return false;
        }
        return node.color == RED;
    }
    private Node rotateLeft(Node node) {
        Node right = node.right;
        node.right = right.left;
        right.left = node;
        right.color = node.color;
        node.color = RED;
        rotations.add("left");  // add rotation to the list
        return right;
    }
    private Node rotateRight(Node node) {
        Node left = node.left;
        node.left = left.right;
        left.right = node;
        left.color = node.color;
        node.color = RED;
        rotations.add("right");  
        return left;
    }
    private void flipColors(Node node) {
        node.color = RED;
        node.left.color = BLACK;
        node.right.color = BLACK;
    }
    // Delete Method
    public void delete(int key) {
        root = delete(root, key);
        root.color = BLACK;
    }
    private Node delete(Node node, int key) {
        if (node == null) {
            return null;
        }
        if (key < node.key) {
            node.left = delete(node.left, key);
        } else if (key > node.key) {
            node.right = delete(node.right, key);
        } else {
            if (node.left == null && node.right == null) {
                return null;
            } else if (node.left == null) {
                node = node.right;
            } else if (node.right == null) {
                node = node.left;
            } else {
                Node min = findMin(node.right);
                node.key = min.key;
                node.right = delete(node.right, min.key);
            }
        }
        if (isRed(node.right) && !isRed(node.left)) {
            node = rotateLeft(node);
        }
        if (isRed(node.left) && isRed(node.left.left)) {
            node = rotateRight(node);
        }
        if (isRed(node.left) && isRed(node.right)) {
            flipColors(node);
        }
        return node;
    }
    private Node findMin(Node node) {
        while (node.left != null) {
            node = node.left;
        }
        return node;
    }
	public RedBlackTree.Node getRoot() {
		return this.root;
	}
	public void clear() {
        root = null;
    }
	public List<String> getRotations() {
		return this.rotations;
	}
	public void clearRotations() {
		this.rotations.clear();
	}
}
/*
 * Scuffed Tree Visualization via GUI
 */
class RedBlackTreeGUI extends JPanel {
    private static final int NODE_DIAMETER = 30;
    private static final int NODE_SPACING = 50;
    private static final int PADDING = 20;
    private RedBlackTree tree;
    private JPanel rotationsPanel;  // new panel to display rotations
    RedBlackTreeGUI() {
    	setLayout(new BorderLayout());
        setPreferredSize(new Dimension(600, 400));
        setBackground(Color.cyan);  
        tree = new RedBlackTree();
        JPanel inputPanel = new JPanel(new FlowLayout(FlowLayout.LEFT));
        JTextField inputField = new JTextField(5);
        
        
        JButton insertButton = new JButton("Insert");
        insertButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                int key = Integer.parseInt(inputField.getText());
                tree.insert(key);
                repaint();
            }
        });
        
        JButton deleteButton = new JButton("Delete");
        deleteButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                int key = Integer.parseInt(inputField.getText());
                tree.delete(key);
                repaint();
            }
        });

        JButton clearButton = new JButton("Clear");
        clearButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
            	tree.clearRotations();
                tree.clear();
                repaint();
            }
        });
        
        JPanel canvasPanel = new JPanel() {
            @Override
            public void paintComponent(Graphics g) {
                super.paintComponent(g);
                Graphics2D g2d = (Graphics2D) g;
                g2d.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);
                drawTree(g2d, tree.getRoot(), getWidth() / 2, PADDING, 0);
            }
        };
        
        canvasPanel.setPreferredSize(new Dimension(600, 400));
        add(canvasPanel, BorderLayout.CENTER);
        inputPanel.add(inputField);
        inputPanel.add(insertButton);
        inputPanel.add(deleteButton);
        inputPanel.add(clearButton);
        add(inputPanel, BorderLayout.SOUTH); 
        
        // Second Panel
        rotationsPanel = new JPanel(); 
        rotationsPanel.setPreferredSize(new Dimension(150, 400));  
        add(rotationsPanel, BorderLayout.EAST); 
    }
    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);

        Graphics2D g2d = (Graphics2D) g;
        g2d.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);
        drawTree(g2d, tree.getRoot(), getWidth() / 2, PADDING, 0);
    }
    private void drawTree(Graphics2D g2d, RedBlackTree.Node node, int x, int y, int level) {
        if (node == null) {
            return;
        }

        int diameter = NODE_DIAMETER - level * 2;
        int radius = diameter / 2;

        g2d.setColor(node.color == RedBlackTree.RED ? Color.RED : Color.BLACK);
        g2d.fillOval(x - radius, y - radius, diameter, diameter);
        g2d.setColor(Color.WHITE);
        g2d.drawString(String.valueOf(node.key), x - 6, y + 4);

        if (node.left != null) {
            int childX = x - NODE_SPACING - level * 10; 
            int childY = y + NODE_DIAMETER + level * 10;  
            g2d.setColor(Color.BLACK);
            g2d.drawLine(x, y + radius, childX, childY - radius);
            drawTree(g2d, node.left, childX, childY, level + 1);
        }
        
        if (node.right != null) {
            int childX = x + NODE_SPACING + level * 10;  
            int childY = y + NODE_DIAMETER + level * 10; 
            g2d.setColor(Color.BLACK);
            g2d.drawLine(x, y + radius, childX, childY - radius);
            drawTree(g2d, node.right, childX, childY, level + 1);
        }
        
        // update rotations panel after each rotation
        List<String> rotations = tree.getRotations();
        rotationsPanel.removeAll();
        for (String rotation : rotations) {
            JButton button = new JButton(rotation);
            button.setPreferredSize(new Dimension(100, 25));
            rotationsPanel.add(button);
        }
        rotationsPanel.revalidate();
        rotationsPanel.repaint();
    }
}
public class Main {
	public static void infix(RedBlackTree.Node current) {
		if(current != null) {
			// LNR
			infix(current.left);
			System.out.print(current.key + " -> ");
			infix(current.right);
		}
	}
	public static void treeTest() {
		try {
			Random rand = new Random();
			RedBlackTree thread = new RedBlackTree();
			for(int i = 0; i < 50; i++) {
				thread.insert(rand.nextInt(100));
			}
			infix(thread.getRoot());
		} catch(Exception x) {
			System.out.println(x);
		}
	}
	public static void guiTest() {
		try {
			JFrame frame = new JFrame();
		    frame.add(new RedBlackTreeGUI());
		    frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		    frame.pack();
		    frame.setVisible(true);
		} catch(Exception x) {
			System.out.println(x);
		}
	}
	public static void main(String[] args) {
		// treeTest();
		 guiTest(); 
	}
}