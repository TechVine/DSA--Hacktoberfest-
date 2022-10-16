class Solution:
    
    #Function to return the size of linked list.
    def getSize(self, head):
        count = 0
        curr_node = head
        while curr_node:
            count +=1
            curr_node = curr_node.next
        return count
    
    #Function to split the list into two halves.
    def splitList(self, source): 
        if source == None or source.next == None:
            frontRef = source
            backRef = None
        else:
            size = self.getSize(source)
            length = (size+1)//2
    
            frontRef = source
            while length>1:
                length-=1
                frontRef = frontRef.next
    
            backRef = frontRef.next
            frontRef.next = None
        
        #returning the two halves of list.
        return [source,backRef]
    
    #Function to merge two halves of list.
    def mergeList(self, head_a,head_b):
        result = LinkedList()
        
        #base cases when either of two halves is null.
        if head_a == None:
            return head_b
        if head_b == None:
            return head_a
    
        #comparing data in both halves and storing the smaller in result and
        #recursively calling the mergeList function for next node in result.
        if head_a.data <= head_b.data:
            result.head = head_a
            result.head.next = self.mergeList(head_a.next,head_b)
        else:
            result.head = head_b
            result.head.next = self.mergeList(head_a, head_b.next)
        
        #returning the resultant list.
        return result.head
    
    
    #Function to sort the given linked list using Merge Sort.
    def mergeSort(self, head):
       
        a = LinkedList()
        b = LinkedList()
    
        if head == None or head.next == None:
            return head
            
        #splitting the list into two halves.
        node_list = self.splitList(head) 
        a.head = node_list[0] 
        b.head = node_list[1] 
    
        #calling the mergeSort function recursively for both parts separately.
        a.head = self.mergeSort(a.head) 
        b.head = self.mergeSort(b.head)
        
        #calling the function to merge both halves.
        return self.mergeList(a.head,b.head)
