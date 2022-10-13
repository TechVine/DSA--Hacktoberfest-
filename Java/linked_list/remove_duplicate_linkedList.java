import java.util.HashSet;

public class remove_duplicate_linkedList {

    static Node head;

    /* Node class */
    static class Node{
        int data;
        Node next;

        Node(int data){
            this.data = data;
            next = null;
        }
    }

    /* Method removes the duplicated elements present in the sorted linkedList */
    static void remove_duplicate(Node head){
 
        HashSet<Integer> set = new HashSet<>();
        Node temp = head;
        Node prev = null;

        while(temp!= null){
            if(set.contains(temp.data))
                prev.next = temp.next;
            else
                set.add(temp.data);

            prev = temp;
            temp = temp.next;
        }
    }

    /* Prints the data of the singly linked */
    static void display_linkedList(Node head){
        Node temp = head;

        while(temp!=null){
            System.out.println(temp.data);
            temp = temp.next;
        }
    }

    /* Driver Code */
    public static void main(String[] args) {
        head = new Node(1);
        head.next = new Node(2);
        head.next.next = new Node(2);
        head.next.next.next = new Node(4);

        remove_duplicate(head);
        display_linkedList(head);
    }
}
