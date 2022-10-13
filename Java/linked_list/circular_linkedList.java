public class circular_linkedList {

    /* Node class */
    static class Node{
        int data;
        Node next;

        Node(int data){
            this.data = data;
            next = null;
        }
    }

    /*   Function to check if a linkedList is circulr or not */
    static boolean isCircular(Node head)
    {
        Node temp = head;
        while(temp != null){
            temp = temp.next;
            if(temp == head)
                return true;
        }

        return false;
    }

    /* Driver Code */
    public static void main(String[] args) {
        Node head = new Node(2);
        head.next = new Node(5);
        head.next.next = new Node(7);
        head.next.next.next = new Node(8);
        head.next.next.next.next = new Node(10);

        System.out.println(isCircular(head));
    }
}
