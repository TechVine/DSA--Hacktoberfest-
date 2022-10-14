#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int x)
    {
        val = x;
        next = nullptr;
    }
};

ListNode *head, *tail;

void PrintList(ListNode *head)
{
    ListNode *curr = head;
    for (; curr != nullptr; curr = curr->next)
    {
        cout << curr->val << "-->";
    }
    cout << "null" << endl;
}

void insertLast(int value) 
{

    ListNode *newnode = new ListNode(value);
    if (head == nullptr)
    {
        head = newnode, tail = newnode;
    }
    else
    {
        tail = tail->next = newnode;
    }
}

ListNode *segregate()
{
    ListNode *oddH = new ListNode(-1), *oddT = oddH;
    ListNode *evenH = new ListNode(-1), *evenT = evenH;
    ListNode *curr = head, *temp;
    while (curr)
    {
        temp = curr;
        curr = curr->next;
        temp->next = nullptr;

        if (temp->val & 1)
        {
            oddT->next = temp;
            oddT = temp;
        }
        else 
        {
            evenT->next = temp;
            evenT = temp;
        }
    }
    evenT->next = oddH->next; 
    return evenH->next;
} 

int main()
{
    insertLast(1);
    insertLast(2);
    insertLast(3);
    insertLast(4);
    cout << "Initial : " << endl;
    PrintList(head);
    ListNode *newHead =segregate();
    cout << "After Segregation: " << endl;
    PrintList(newHead);
    return 0;
}