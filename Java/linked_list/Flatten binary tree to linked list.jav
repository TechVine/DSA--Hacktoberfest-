class LinkedList
{
    public static void flatten(Node root)
    {
        //code here
        if (root == null || root.left == null &&
	        root.right == null) {
    		return;
    	}
    	
    	Node t = root.right;

    	// if root.left exists then we have
    	// to make it root.right
    	if (root.left != null) {
    
    		// move left recursively
    		flatten(root.left);
    
    		// store the node root.right
    		Node tmpRight = root.right;
    		root.right = root.left;
    		root.left = null;
    
    		// find the position to insert
    		// the stored value
    		t = root.right;
    		while (t.right != null) {
    			t = t.right;
    		}
    
    		// insert the stored value
    		t.right = tmpRight;
    	}
    
    	// now call the same function
    	// for root.right
    	flatten(t);
    }
}
