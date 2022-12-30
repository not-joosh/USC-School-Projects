import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;

class Node {
	
	// Attributes
	protected int key;
	protected Node leftChild, rightChild;
	  
	// Constructors
	Node() { this.leftChild = this.rightChild = null; }
	
	Node(int dataIn) {
		this.key = dataIn;
		this.leftChild = this.rightChild = null;
	}
	
	// Getters
	public int getKey() { return this.key; }
	public Node getLeft() { return this.leftChild; }
	public Node getRight() { return this.rightChild; }
	
	// Setters
	public void setKey(int dataIn) { this.key = dataIn; }
	public void setLeft(Node nodeIn) { this.leftChild = nodeIn; }
	public void setRight(Node nodeIn) { this.rightChild = nodeIn; }
}

class FactorTree {
	// Attributes
	protected Node root; // Root holds all the factors of the tree
	protected ArrayList<Node> leafFactors; // Contains only leaf Nodes
	
	// Constructors
	FactorTree() {
		this.root = null;
		this.leafFactors = null;
	}
	FactorTree(int valueIn) {
		// Creates the Factor Tree
		this.root = null;
	    this.root = makeTree(this.root, valueIn);
	    // Getting leaf Nodes in Tree in BFS Traversal
	    this.leafFactors = new ArrayList<Node>();
	    saveLeaves(this.root, this.leafFactors);
	}
	
	// Methods
	private Node makeTree(Node currentNode, int dataIn) {
		// Using Eratosthenes to generate prime factors
		boolean[] primes = new boolean[dataIn + 1];
		Arrays.fill(primes, true);
		primes[0] = primes[1] = false;
		for (int i = 2; i * i <= dataIn; i++) {
			if (primes[i]) {
				for (int j = i * i; j <= dataIn; j += i) {
		    	  primes[j] = false;
		    	}
			}
		}
		currentNode = new Node(dataIn);
		for (int i = 2; i <= dataIn / 2; i++) {
			if (dataIn % i != 0 || !primes[i])
				continue;
			currentNode.leftChild = makeTree((currentNode.leftChild), i);
			currentNode.rightChild = makeTree((currentNode.rightChild), currentNode.key / i);
			return currentNode;
		}
		return currentNode;
	}
	protected void saveLeaves(Node rootNode, ArrayList<Node> leafFactors) {
		// If there is not Root
		if (rootNode == null)
			return;
		// Creating QUEUE and adding the first node
		Queue<Node> q = new LinkedList<>();
		q.add(rootNode);
		// Going through each Level (BFS) Traversal to save
		// the Factors with no children
		while (!q.isEmpty()) {
			Node currentNode = q.peek();
			q.remove();
			if (currentNode.leftChild != null)
				q.add(currentNode.leftChild);
			if (currentNode.rightChild != null)
				q.add(currentNode.rightChild);
			if (currentNode.rightChild == null && currentNode.leftChild == null)
				leafFactors.add(currentNode);
		}
	}
	protected void printTree() { // BFS Traversal 
		Node rootNode = this.root;
		// If there is not Root
		if (rootNode == null) return;
		// Creating QUEUE and adding the first node
		Queue<Node> q = new LinkedList<>();
		q.add(rootNode);
		// Going through each Level (BFS) Traversal to print the tree
		System.out.print("\nFactor tree of '" + rootNode.key + "':");	
		while (!q.isEmpty()) {
			Node currentNode = q.peek();
			System.out.print(currentNode.key + "-> ");
		    q.remove();
		    if (currentNode.leftChild != null)
		    	q.add(currentNode.leftChild);
		    if (currentNode.rightChild != null)
		    	q.add(currentNode.rightChild);
		}
		System.out.println();
	}
	protected void printFactors() {
		// If there is not Root
		if (this.leafFactors == null) {
			System.out.println("There are no factors to show.");
			return;
		}
		// Printing the Leaf Factors
		System.out.print("\nLeaf factors: ");
		for (int i = 0; i < this.leafFactors.size(); i++) {
			System.out.print(this.leafFactors.get(i).key + " ");
		}
		System.out.println();
	}

}
class PerfectSquare extends FactorTree {
	
	// Attributes
	private int value;
	private boolean isPerfectSquare;
	
	// Constructors
	PerfectSquare() {
		this.isPerfectSquare = false;
	}
	PerfectSquare(int valueIn) {
		super(valueIn);
	    this.value = valueIn;
	    // Define whether the value is a perfect square or not
	    this.isPerfectSquare = (int) Math.sqrt(valueIn) == (double) Math.sqrt(valueIn);
	}
	// Setter
	public void setValue(int valueIn) {
		this.value = valueIn;
		// Define whether the value is a perfect square or not
		this.isPerfectSquare = (int) Math.sqrt(valueIn) == (double) Math.sqrt(valueIn);
	}
	// Getters
	public String toString() {
		return this.isPerfectSquare ? "Integer: " 
				+ this.value + "\t-\tPERFECT SQUARE" : "Integer: " 
				+ this.value + "\t-\tNOT PERFECT SQUARE";
	}
	public int getValue() { return this.value; }
	public int getN() {
		// Compute N value to make a perfect square
		int n = 1;
		// Find leaf nodes with odd occurrences
		for (int i = 0; i < super.leafFactors.size(); i++) {
			int count = 0;
			int searchKey = super.leafFactors.get(i).key;
			for (int j = i; j < super.leafFactors.size() && super.leafFactors.get(j).key == searchKey; j++) {
				count++;
			}
			// If the count is odd, add the leaf node to the list
			if (count % 2 != 0) {
				n *= super.leafFactors.get(i).key;
			}
			// Skip all the other leaf nodes with the same key
			i += count - 1;
		}
		return n;
	}
}

class GUI extends JFrame {
	private JTextField mField;
	private JLabel resultLabel;

	public GUI() {
		super("Perfect Square");
		setLayout(new FlowLayout());
	    setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	    setSize(500, 400);
	    getContentPane().setBackground(Color.BLACK);

	    // Text field
	    mField = new JTextField(10);
	    mField.setBackground(Color.BLACK);
	    mField.setForeground(Color.WHITE);
	    add(mField);

	    // Calculate Button
	    JButton calculateButton = new JButton("Compute");
	    calculateButton.setBackground(Color.BLACK);
	    calculateButton.setForeground(Color.YELLOW);
	    calculateButton.addActionListener((ActionListener) new ActionListener() {
	    	public void actionPerformed(ActionEvent event) {
	    		int m = Integer.parseInt(mField.getText());
		        PerfectSquare ps = new PerfectSquare(m);
		        int n = ps.getN();
		        int mValue = ps.getValue();
		        resultLabel.setText("The smallest number m * n to be a perfect square is " + n + " (m * n = " + (n * mValue) + ")");
	
		        FactorTree tree = new FactorTree(n );
				// Creating a panel to hold the factor tree visualization
				JPanel treePanel = new JPanel();
				treePanel.setLayout(new BorderLayout());
		
				// Creating a container for the tree visualization
				JPanel treeContainer = new JPanel();
				treeContainer.setLayout(new FlowLayout());
		
				// Recursively generating the tree visualization using the root of the FactorTree
				generateTreeVisualization(tree.root, treeContainer);
		
				// Add the container to the tree panel
				treePanel.add(treeContainer);
		
				// Add the tree panel to the GUI
				add(treePanel, BorderLayout.WEST);
			}
	    });
	    add(calculateButton);
	    // Result Label
	    resultLabel = new JLabel("Find any Integer's 'n' to make it a Perfect Square.");
	    resultLabel.setBackground(Color.BLACK);
	    resultLabel.setForeground(Color.YELLOW);
	    add(resultLabel);
	}
	private void generateTreeVisualization(Node node, JPanel container) {
		// Create a panel to hold the node visualization
	    JPanel nodePanel = new JPanel();
	    nodePanel.setLayout(new FlowLayout());
	    
	    // Create a label to display the value of the node
	    JLabel nodeLabel = new JLabel(String.valueOf(node.key));
	    nodeLabel.setForeground(Color.WHITE);
	    
	    // Set the background color and size of the node visualization
	    nodePanel.setBackground(node.leftChild == null && node.rightChild == null ? Color.GREEN : Color.RED);
	    nodePanel.setPreferredSize(new Dimension(50, 50));
	    // Add the label to the node panel
	    nodePanel.add(nodeLabel);
	    // Add the node panel to the container
	    container.add(nodePanel);
	    // Recursively generate the visualization for the left and right children of the node
	    if (node.leftChild != null) {
	        generateTreeVisualization(node.leftChild, container);
	    }
	    if (node.rightChild != null) {
	        generateTreeVisualization(node.rightChild, container);
	    }
	}
}

class Main {
	static Scanner input = new Scanner(System.in);
	public static void perfectSquareTest() {
		System.out.print("Enter an integer m: ");
		PerfectSquare m = new PerfectSquare(input.nextInt());
		System.out.print("The smallest number m * n to be a perfect"
						+ " square is " + m.getN() + "\n"
						+ "m*n is " + (m.getN() * m.getValue()));
	}
	public static void guiTest() {
		try {
			GUI gui = new GUI();
		    gui.setVisible(true);
		} catch(Exception x) {
			System.out.println(x);
		}
	}
	public static void main(String[]Args) { 
		/*
		 * 	I made this program just for fun... Excuse the terrible
		 *  code and poor design. I'm just experimenting lmao.
		 */
//		perfectSquareTest();
		guiTest();
	}
}


