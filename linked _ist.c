#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} * head, *ptr;
void create()
{

    int c;
    int i = 0;

    do
    {
        struct node *temp = (struct node *)(malloc(sizeof(struct node)));

        printf("ENTER THE VALUE OF %d ELEMENT : ", (i + 1));
        scanf("%d", &(temp->data));
        i++;
        temp->next = NULL;

        if (head == NULL)
        {
            //head = temp;   //both codes are correct and has its own significance
            head=ptr=temp;

        }
        else
        {
           /* ptr = head;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }*/

            ptr->next = temp;
            ptr=temp;
        }
        printf("WANT TO ADD MORE ELEMENT[1/0] : ");
        scanf("%d", &c);
    } while (c == 1);
}

struct node * reverseList(struct node*head)
{
    struct node*prev,*current,*nextNode;
    prev=NULL;
    current=nextNode=head;
    while(nextNode->next!=NULL)
    {
        nextNode=nextNode->next;
        current->next=prev;
        prev=current;
        current=nextNode;
    }
   current->next=prev;
    head=current;
    return(head);
}

void display(struct node *ptr3)
{
    

    while (ptr3->next != NULL)
    {
        printf("%d->", ptr3->data);
        ptr3 = ptr3->next;
    };
    printf("%d", ptr3->data);
}

int main()
{

    create();
    printf("after create function\n");
    display(head);
    printf("\n*******************\nafter reversal\n");
    head=reverseList(head);
    printf("\n*******************\n");
    display(head);
    return 0;
}
