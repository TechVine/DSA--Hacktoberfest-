class Linked
{
    //Function to insert a node at the beginning of the linked list.
    Node insertAtBeginning(Node head, int x)
    {
        //storing the new node with data in a pointer.
        Node temp = new Node(x);  
        
        //if the linked list is null we just return the new node.
        if(head == null)        
            return temp;
            
        //else we just add the list head to the link part(next) of new node. 
        //the new node gets inserted at beginning and becomes the first node.
        temp.next = head; 
        //returning the linked list.
        return temp;
    }
    
    //Function to insert a node at the end of the linked list.
    Node insertAtEnd(Node head, int x)
    {
        Node temp = new Node(x);
        
        //if the linked list is null we just return the new node.
        if(head == null){
            return temp;
        }
        else{
            Node ptr = head;
            //we use a pointer to find the last node of list.
            while(ptr.next!=null){
                ptr=ptr.next;   
            }
            //we add new node to the link part(next) of last node in the list. 
            //the new node gets inserted at end and becomes the last node.
            ptr.next = temp;
            temp.next = null;
        }
        //returning the linked list.
        return head;
    }
}
