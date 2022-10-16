Node deleteNode(Node head, int x)
	{
		/*if(head == null)
			return null;	
		if(x==1)
		{
			Node temp = head;
			head = temp.next;
			return head;
		}else
		{
			Node temp = head;
			Node back = temp;;
			x--;
			while(temp != null && x>1)
			{
				back = temp;
				temp = temp.next;
				x--;
			}
			
			back.next = temp.next;
			return head;
		}*/
		if (head == null)
            return null;
 
        // Store head node
        Node temp = head;
 
        // If head needs to be removed
        if (x == 1)
        {
            head = temp.next;   // Change head
            return head;
        }
 
      
		x--;
		//Node back;
        for (int i=1; temp!=null && i<x; i++)
		{
			//back = temp;
            temp = temp.next;
		}
 
        // If position is more than number of ndoes
        if (temp == null || temp.next == null)
            return null;
 
		if(temp.next.next == null)
			temp.next = null;
		else
			temp.next = temp.next.next;
        // Node temp->next is the node to be deleted
        // Store pointer to the next of node to be deleted
        //Node next = temp.next.next;
 
        //temp.next = next;  
		
		return head;
	}
}
