// Program to split a circular linked list
// into two halves
#include <bits/stdc++.h>
using namespace std;

/* structure for a node */
class Node
{
	public:
	int data;
	Node *next;
};

void splitList(Node *head, Node **head1_ref,
						Node **head2_ref)
{
	Node *slow_ptr = head;
	Node *fast_ptr = head;
	
	if(head == NULL)
		return;

	while(fast_ptr->next != head &&
		fast_ptr->next->next != head)
	{
		fast_ptr = fast_ptr->next->next;
		slow_ptr = slow_ptr->next;
	}
	
	/* If there are even elements in list
	then move fast_ptr */
	if(fast_ptr->next->next == head)
		fast_ptr = fast_ptr->next;
		
	/* Set the head pointer of first half */
	*head1_ref = head;
		
	/* Set the head pointer of second half */
	if(head->next != head)
		*head2_ref = slow_ptr->next;
		
	/* Make second half circular */
	fast_ptr->next = slow_ptr->next;
		
	/* Make first half circular */
	slow_ptr->next = head;
}

void push(Node **head_ref, int data)
{
	Node *ptr1 = new Node();
	Node *temp = *head_ref;
	ptr1->data = data;
	ptr1->next = *head_ref;
		
	/* If linked list is not NULL then
	set the next of last node */
	if(*head_ref != NULL)
	{
		while(temp->next != *head_ref)
		temp = temp->next;	
		temp->next = ptr1;
	}
	else
		ptr1->next = ptr1; /*For the first node */
	
	*head_ref = ptr1;
}

/* Function to print nodes in
a given Circular linked list */
void printList(Node *head)
{
	Node *temp = head;
	if(head != NULL)
	{
		cout << endl;
		do {
		cout << temp->data << " ";
		temp = temp->next;
		} while(temp != head);
	}
}

// Driver Code
int main()
{
	int list_size, i;
		
	/* Initialize lists as empty */
	Node *head = NULL;
	Node *head1 = NULL;
	Node *head2 = NULL;
	
	/* Created linked list will be 12->56->2->11 */
	push(&head, 12);
	push(&head, 56);
	push(&head, 2);
	push(&head, 11);
	
	cout << "Original Circular Linked List";
	printList(head);	
	
	/* Split the list */
	splitList(head, &head1, &head2);
	
	cout << "\nFirst Circular Linked List";
	printList(head1);
	
	cout << "\nSecond Circular Linked List";
	printList(head2);
	return 0;
}

//output:

// Original Circular Linked List
// 11 2 56 12 
// First Circular Linked List
// 11 2 
// Second Circular Linked List
// 56 12
