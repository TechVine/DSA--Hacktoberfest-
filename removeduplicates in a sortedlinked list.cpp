#include <bits/stdc++.h>
using namespace std;
  
struct Node {
    int data;
    Node* next;
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};
  

Node* removeDuplicates(Node* head)
{
    Node *temp = head, *prev = head;
    
    while (temp != NULL) {
        
        if (temp->data != prev->data) {
            
            prev->next = temp;
            prev = temp;
        }
       
        temp = temp->next;
    }
   
    if (prev != temp)
        prev->next = NULL;
    return head;
}
