class LinkedList
{
    static int countTriplets(Node head, int x) 
{ 
    Node ptr, ptr1, ptr2; 
    int count = 0; 
   
    // unordered_map 'um' implemented as hash table 
    HashMap<Integer,Node> um = new HashMap<Integer,Node>(); 
   
    // insert the <node data, node pointer> tuple in 'um' 
    for (ptr = head; ptr != null; ptr = ptr.next) 
        um.put(ptr.data, ptr); 
   
    // generate all possible pairs 
    for (ptr1 = head; ptr1 != null; ptr1 = ptr1.next) 
        for (ptr2 = ptr1.next; ptr2 != null; ptr2 = ptr2.next) { 
   
            // p_sum - sum of elements in the current pair 
            int p_sum = ptr1.data + ptr2.data; 
   
            // if 'x-p_sum' is present in 'um' and either of the two nodes 
            // are not equal to the 'um[x-p_sum]' node 
            if (um.containsKey(x - p_sum) && um.get(x - p_sum) != ptr1 
                && um.get(x - p_sum) != ptr2) 
   
                // increment count 
                count++; 
        } 
   
    // required count of triplets 
    // division by 3 as each triplet is counted 3 times 
    return (count / 3); 
} 
}
