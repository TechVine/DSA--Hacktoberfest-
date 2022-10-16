class Linked
{
	Node head;
	//Function to convert binary tree to doubly linked list and return it.
	Node bToDLL(Node root)
	{
	    //base case for recursion.
		if(root == null)
			return null;
		
		//calling function recursively to convert right subtrees.
		bToDLL(root.right);
		
		//inserting root into doubly linked list. 
		root.right = head;
		
		//changing left pointer of previous head.
		if(head != null)
			head.left = root;
		
		//changing head of doubly linked list.
		head = root;
		
		//calling function recursively to convert left subtrees.
		bToDLL(root.left);
		
		return head;
	}
}
