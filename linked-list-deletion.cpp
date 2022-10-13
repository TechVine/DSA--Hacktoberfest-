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

    // HacktoberFest Task Deletion
    void deleteAtFront();
    void deleteInBetween(int index);
    void deleteAtLast();

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

/********************** Deletion *************************/
void LinkedList::deleteAtFront(){
    if (!isEmpty(head))
    {
        Node *temp = head;
        head = temp->next;
        temp->next = NULL;
        cout << "deleted front: " << temp->data << endl ; 
        delete temp;
    } else {
        cout << "List is empty...\n";
    }
}
void LinkedList::deleteInBetween(int index){
    if (!isEmpty(head))
    {
        Node *temp = head;
        int listLen = 0;
        while (temp != NULL)
        {
            temp = temp->next;
            listLen++;
        }
        if (index < listLen-1 && index != 0) // if index is zero means the head Node
        {
            Node* prev;
            temp = head;
            for (int i = 0; i < index; i++)
            {
                prev = temp;
                temp = temp->next;
            }
            prev->next = temp->next;
            temp->next = NULL;
            cout << "deleted " << temp->data << " Index: " << index << endl ;
            delete temp;
        }
        else
        {
            cout << "\n--------- IndexOutOfRangeError" << endl ;
            cout << "\tcan't delete at index: " << index << endl;
        }

    } else {
        cout << "List is empty...\n";
    }
}

void LinkedList::deleteAtLast(){
    if (!isEmpty(head))
    {
        // store the head into temp
        Node *temp = head, *lastSecond;
        while (temp->next != NULL) // lastSecond will point to lastSecond Node
        {
            lastSecond = temp;
            temp = temp->next;
        }

        if (head->next == NULL) // it means, there is only one single-node, i.e. head
            head = NULL;
        else // break the link of last-Node and lastSecond node
            lastSecond->next = NULL;

        cout << "deleted last: " << temp->data << endl;
        delete temp;
    } 
    else
        cout << "List is empty...\n";
    
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
        cout << endl ;
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
    ll.insertNode(6);
    ll.insertNode(7);
    ll.insertNode(8);
    ll.insertNode(9);
    ll.insertNode(10);

    ll.deleteAtFront();
    ll.deleteAtFront();
    ll.deleteAtLast();
    ll.deleteAtLast();

    // 1 <= index <= last_element_index-1 ------> if it's not then IndexOutOfRangeError
    ll.deleteInBetween(0); // IndexOutOfRangeError

    ll.display(head);
    ll.deleteInBetween(1);

    ll.display(head);
    ll.deleteInBetween(3);

    ll.display(head);
    ll.deleteInBetween(4); // IndexOutOfRangeError because at this time there are only 4 elements are present

    ll.display(head);
    
    return 0;
}