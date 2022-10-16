#Function to insert a node at the beginning of the linked list.
    def insertAtBegining(self,head,x):
        
        #storing the new node with data in a pointer.
        temp = Node(x)
        #if the linked list is null we just return the new node.
        if head is None:
            return temp
            
        #else we just add the list head to the link part(next) of new node.
        #the new node gets inserted at beginning and becomes the first node.
        temp.next = head
        
        #returning the linked list.
        return temp
    
    #Function to insert a node at the end of the linked list.
    def insertAtEnd(self,head,x):
        temp = Node(x)
        #if the linked list is null we just return the new node.
        if head is None:
            return temp
            
        ptr = head
        #we use a pointer to find the last node of list.
        while ptr.next:
            ptr=ptr.next;
            
        #we add the new node to the link part(next) of last node in the list. 
        #the new node gets inserted at end and becomes the last node.
        ptr.next = temp;
        
        #returning the linked list.
        return head
