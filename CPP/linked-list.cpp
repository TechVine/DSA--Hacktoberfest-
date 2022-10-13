#include <iostream>
using namespace std;

// Node
class Node {
public:
    int data = 0;
    Node *next;
    Node () {
        data = 0;
        next = NULL;
    }
    Node(int data){
        this->data = data;
        next = NULL;
    }
};

// Some Global Nodes
Node* head;
Node* first;

// LinkedList 
class LinkedList {
public:
    LinkedList(){
        head = NULL;
    }
    // insert at begining
    bool isEmpty(Node* head) {
        if (head == NULL) return true;
        return false;
    }

    void insertNode(int data);

    // HacktoberFest Task
    void insertAtFront(int data);
    void insertInBetween(int data, int index);
    void insertAtLast(int data);

    // display Linked-List
    void display(Node* head);
    
};

// insert Node
void LinkedList::insertNode(int data) {
    // if list is not empty
    if (!isEmpty(head))
    {
        first = head;
        Node* node = new Node(data);
        while (first->next != NULL)
        {
            first = first->next;
        }
        first->next = node;
        cout << "inserted " << node->data << endl;
    }
    else {
        head = new Node(data);
        cout << "inserted " << head->data << endl;
    }
}

void LinkedList::insertAtFront(int data) {
    // if list is not empty
    if (!isEmpty(head))
    {
        // create node and set the data of that node
        Node* node = new Node(data);
        // set the next of newly created node to head and
        node->next = head;
        // set the head to newly created node
        head = node;
        cout << "inserted at front: " << head->data << endl;
    } else {
        cout << "List is empty...";
    }
}

void LinkedList::insertAtLast(int data) {
    // if list is not empty
    if (!isEmpty(head))
    {
        // create node and set the data of that node
        Node* node = new Node(data);
        Node* temp = head;
        // traverse the list, until we didn't get the last node
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        // we are on the last node,
        temp->next = node;
        cout << "inserted at last: " << node->data << endl;
    } else {
        cout << "List is empty...\n";
    }
}

// Insert in Between 
void LinkedList::insertInBetween(int data, int index) {
    if (!this->isEmpty(head))
    {
        int listLen = 0;
        Node* temp = head;
        while (temp!= NULL)
        {
            temp = temp->next;
            listLen++;
        }
        // check if the index is less then listLen, then and only then we can insert the 
        // node else we can't insert the node
        temp = head;
        if (index < listLen && index != 0) // if the index is 0 means we're inserting the node at head
        {
            for (int i = 1; i < index; i++)
            {
                temp = temp->next;   
            }
            // create node
            Node* node = new Node(data);
            node->next = temp->next;
            temp->next = node;
            cout << "Inserted at index: " << index << " data: " << node->data << endl ; 
        }
        else {
            cout << "\n----- IndexOutOFRangeError...\n";
            cout << "can't insert: " << data << " at index: " << index << " list-len: " << listLen << endl ;
        }
    }
}

void LinkedList::display(Node* head) {
    Node* temp = head;
    if (head != NULL)
    {
        cout << "\nLinked-List elements: ";
        while (temp != NULL)
        {
            cout << temp->data << " " ;
            temp = temp->next;
        }
        return;
    }
    cout << "Linked-List is empty...\n";
}

int main()
{
    LinkedList ll;
    ll.insertNode(1);
    ll.insertNode(2);
    ll.insertNode(3);
    ll.insertNode(4);
    ll.insertNode(5);

    ll.insertAtFront(0);
    ll.insertAtFront(-1);
    ll.insertAtFront(-2);
    ll.insertAtLast(6);
    ll.insertInBetween(100, 5);
    ll.insertInBetween(101, 6);
    ll.insertInBetween(102, 7);
    ll.insertInBetween(100, 12);

    ll.display(head);
    
    return 0;
}