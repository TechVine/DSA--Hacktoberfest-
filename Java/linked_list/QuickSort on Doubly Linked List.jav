class Linked
{
    public static Node partition(Node l, Node h)
    {
        int x  = h.data;
   
        Node i = l.prev;
 
        for(Node j = l; j != h; j = j.next)
        {
            if (j.data <= x)
            {
                
                i = (i == null)? l : i.next;
     
                int t = i.data;
                i.data = j.data;
                j.data = t;
            }
        }
        i = (i == null)? l : i.next; 
        int t = i.data;
        i.data = h.data;
        h.data = t;
    return i;
    }
}
