class Linked
{
    //Function to sort the given linked list using Merge Sort.
    public static Node mergeSort(Node head)
    {
        if(head == null || head.next == null)
           return head;
        
        //splitting the list into two halves.   
        Node middle = getMiddle(head);
        Node nextofmiddle = middle.next;
        middle.next = null;
        
        //calling the mergeSort function recursively for both parts separately.
        Node left = mergeSort(head);
        Node right = mergeSort(nextofmiddle);
        
        //calling the function to merge both halves.
        Node sortedlist = sortedMerge(left, right);
        return sortedlist;
        
    }
    
    //Function to merge two halves of list.
    public static Node sortedMerge(Node a, Node b)
    {
        Node result = null;
        
        //base cases when either of two halves is null.
        if (a == null)
            return b;
        if (b == null)
            return a;
 
        //comparing data in both halves and storing the smaller in result and
        //recursively calling the mergeList function for next node in result.
        if (a.data <= b.data) 
        {
            result = a;
            result.next = sortedMerge(a.next, b);
        } 
        else
        {
            result = b;
            result.next = sortedMerge(a, b.next);
        }
        
        //returning the resultant list.
        return result;
    }
    
    //Function to split the list into two halves.
    public static Node getMiddle(Node h)
    {
        if (h == null)
            return h;
            
        //using two pointers to find the midpoint of list.
        Node fastptr = h.next;
        Node slowptr = h;
         
        //first pointer, slow moves 1 node and second pointer, fast moves
        //2 nodes in one iteration.
        while (fastptr != null)
        {
            fastptr = fastptr.next;
            if(fastptr!=null)
            {
                slowptr = slowptr.next;
                fastptr=fastptr.next;
            }
        }
        //slow is before the midpoint in the list, so we split the 
        //list in two halves from that point.
        return slowptr;
    }

}

