class Linked
{
    public static Node addPolynomial(Node p1,Node p2)
    {
        
    Node sum = null;
    Node ptr = null;
    while( p1 != null || p2 != null)
    {
        int p,c;
        
        if(p1==null)
        {
            // if p1 is NULL we pick values from p2
            p = p2.pow;
            c = p2.coeff;
            p2 = p2.next;
        }
        
        else if(p2==null)
        {
            // if p2 is NULL we pick values from p1
            p = p1.pow;
            c = p1.coeff;
            p1 = p1.next;
        }
        
        else
        {
            int pow1 = p1.pow, pow2 = p2.pow;
            
            // picking max power
            if (pow1 >= pow2) 
            {
                p = pow1;
            }
            else
            {
                p = pow2;
            }
            
            c = 0;
            if (pow1 == p) 
            {
                c += p1.coeff;
            }
            if (pow2 == p) 
            {
                c += p2.coeff;
            }
            // picking coefficient of greater power
            
            if (pow1 >= pow2) p1 = p1.next;
            if (pow2 >= pow1) p2 = p2.next;
        }
        
        if(ptr == null)
            sum = ptr = new Node(c,p);
            // creating head of sum plynomial
        else
        {
            // adding new quantity to polynomial
            ptr.next = new Node(c,p);
            ptr = ptr.next;
        }
    }
    return sum;
    }
}
