class Linked
{
	boolean isCircular(Node head)
	{
		if(head == null)
			return true;
		Node temp = head.next;
		while(temp != null && temp != head )
		
			temp = temp.next;
		return (temp == head);
	}
}
