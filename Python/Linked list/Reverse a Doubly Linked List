def reverseDLL(head): 
    temp = None
    current = head 

    while current is not None: 
        temp = current.prev  
        current.prev = current.next
        current.next = temp 
        current = current.prev 

    if temp is not None: 
        head = temp.prev
    return head
