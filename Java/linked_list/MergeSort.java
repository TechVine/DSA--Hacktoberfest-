
 // Java program for merge sort in linked list
//import java.io.*;
//import java.lang.*;
//import java.util.*;

// Node Class
class Node {
	int data;
	Node next;
	Node(int key)
	{
		this.data = key;
		next = null;
	}
}

class GFG {

	// Function for merge sort
	static Node mergeSort(Node head)
	{
		if (head.next == null)
			return head;

		Node mid = findMid(head);
		Node head2 = mid.next;
		mid.next = null;
		Node newHead1 = mergeSort(head);
		Node newHead2 = mergeSort(head2);
		Node finalHead = merge(newHead1, newHead2);

		return finalHead;
	}

	// Function to merge two linked lists
	static Node merge(Node head1, Node head2)
	{
		Node merged = new Node(-1);
		Node temp = merged;
	
		// While head1 is not null and head2
		// is not null
		while (head1 != null && head2 != null) {
			if (head1.data < head2.data) {
				temp.next = head1;
				head1 = head1.next;
			}
			else {
				temp.next = head2;
				head2 = head2.next;
			}
			temp = temp.next;
		}
	
		// While head1 is not null
		while (head1 != null) {
			temp.next = head1;
			head1 = head1.next;
			temp = temp.next;
		}
	
		// While head2 is not null
		while (head2 != null) {
			temp.next = head2;
			head2 = head2.next;
			temp = temp.next;
		}
		return merged.next;
	}

	// Find mid using The Tortoise and The Hare approach
	static Node findMid(Node head)
	{
		Node slow = head, fast = head.next;
		while (fast != null && fast.next != null) {
			slow = slow.next;
			fast = fast.next.next;
		}
		return slow;
	}

	// Function to print list
	static void printList(Node head)
	{
		while (head != null) {
			System.out.print(head.data + " ");
			head = head.next;
		}
	}

	// Driver Code
	public static void main(String[] args)
	{
		Node head = new Node(5);
		Node temp = head;
		temp.next = new Node(12);
		temp = temp.next;
		temp.next = new Node(7);
		temp = temp.next;
		temp.next = new Node(18);
		temp = temp.next;
		temp.next = new Node(6);
		temp = temp.next;
		temp.next = new Node(1);
		temp = temp.next;

		// Apply merge Sort
		head = mergeSort(head);
		System.out.print("\nSorted Linked List is: \n");
		printList(head);
	}
}

