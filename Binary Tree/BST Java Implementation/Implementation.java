import java.util.*;

class Implementation {
  
    static class Node{
    int val;
    Node left;
    Node right;
    public Node(int val){
        this.val = val;
        left = null;
        right = null;
    }
  };

  
public static void main(String[] args) {
    ArrayList<Integer> v = new ArrayList<>(Arrays.asList(1, 2, 3, 4, 5, 6, 7));
    Node root = new Node(0);  // Create an empty node to start with
    createTree(root, v);
    
    // Example: Implement a method to print the tree, e.g., inorder traversal
    inorderTraversal(root);
}

// Inorder traversal to print the tree's values
public static void inorderTraversal(Node root) {
    if (root != null) {
        inorderTraversal(root.left);
        System.out.print(root.val + " ");
        inorderTraversal(root.right);
    }
}
    
  public static void createTree(Node root0, ArrayList<Integer> v) {
        // Initialize the root node with the first element
        root0.val = v.get(0);
        root0.left = null;
        root0.right = null;

        int n = v.size();

        for (int i = 1; i < n; i++) {
            int x = v.get(i);
            Node temp = root0;
            Node parent = null;

            // Traverse the tree to find the correct position for the new node
            while (temp != null) {
                parent = temp;
                if (x < temp.val) {
                    temp = temp.left;
                } else if (x > temp.val) {
                    temp = temp.right;
                } else {
                    // If the value already exists, break to avoid duplicates
                    break;
                }
            }

            // Only create a new node if the value is not already in the tree
            if (temp == null) {
                Node newNode = new Node(x);
                newNode.left = null;
                newNode.right = null;

                // Insert the new node under the identified parent
                if (x < parent.val) {
                    parent.left = newNode;
                } else {
                    parent.right = newNode;
                }
            }
        }
    }
}
