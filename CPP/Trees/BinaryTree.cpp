// Binary tree (BT) in CPP : yashsarnaik22
#include<iostream>
#include<queue>
using namespace std;
class node{ //node class
    public:
        int data;
        node* left;
        node* right;

    node (int d){ //constructor
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};
node* buildTree(node* root){ //creating binary tree
    cout<<"enter the data:"<<endl;
    int data;
    cin>>data;
    root= new node(data);

    if(data==-1) //enter data as -1 if you want NULL
    {
        return NULL;
    }
//recursive function to enter data
cout<<"enter data for inserting in left of "<<data<<endl; //insert in left node
root->left=buildTree(root->left);
cout<<"enter data inserting in right of "<<data<<endl; //insert in right node
root->right=buildTree(root->right); 
return root;
}
//level order traversal
node* levelordertraversal(node* root)
{ 
    queue<node*>q; //creating a queue
    q.push(root); //push root first
    q.push(NULL); //seperator:- to seperate levels 


    while(!q.empty())
    { //printing until queue is empty
        node* temp= q.front(); //let first element of queue be temp to print it's value
        
        q.pop(); //pop the queue when element is printed
        if(temp==NULL) //if null, end of level 
        {
            cout<<endl; //therefore change the line, go to new line
            if(!q.empty())
            { // if q is not empty elements are still present(that are node i.e left and right of roots)
                q.push(NULL); // so push seperator so line changes after iteration
            }
        }
        else
        { //if not null
            cout<<temp->data<<" "; //print data
            if(temp->left)
            { //push left first(of the node) so that it will be printed next
                    q.push(temp->left);
            }
                if(temp->right)
            { //push right next
                    q.push(temp->right);
            }
        }
    }
}
//inorder traversal LNR
void inorder(node* root){
//base case
    if(root==NULL){
        return;
    }
    inorder(root->left); //left
    cout<<root->data<<" "; //node
    inorder(root->right); //right
}
//preorder travesal NLR
void preorder(node* root){
    if(root== NULL){
        return;
    }
    cout<<root->data<<" "; //node
    preorder(root->left); //left
    preorder(root->right); //right
}
//postorder traversal LRN
void postorder(node* &root)
{
    if(root==NULL){
        return;
    }
    postorder(root->left); //left
    postorder(root->right); //right
    cout<<root->data<<" "; //node

}
void buildfromlevelorder(node* &root){ //creating tree from given level order traversal
    queue<node*>q; //creating q
    int data, leftdata, rightdata; //defining data variable left right and node
    cout<<"enter data for root: ";
    cin>>data; //taking in data
    root=new node(data); //assigning entered data as root
    q.push(root); //push root to queue

    while(!q.empty()){ //till the q becomes empty
        node* temp= q.front(); // let temp be front of queue
        q.pop(); //pop to queue 

        cout<<"enter left node for: "<<temp->data<<endl; //enter left node of the present root
        cin>>leftdata;
 
        if(leftdata!=-1) //if -1 entered that means null, so go to next position(i.e right)
        {
            temp->left=new node(leftdata);
            q.push(temp->left);
        }

        cout<<"enter right node for: "<<temp->data<<endl; //enter right node to present root
        cin>>rightdata;

        if(rightdata!=-1) //if -1 i.e NULL move to next element in the queue
        {
            temp->right=new node(rightdata); 
            q.push(temp->right);
        }
    }
}
int main(){

    node* root=NULL;
    buildfromlevelorder(root);

    levelordertraversal(root);
    /*root= buildTree(root);
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    cout<<"level order traversal: "<<endl;
    levelordertraversal(root);
    cout<<endl;

    cout<<"\nInorder traversal is: \n";
    inorder(root);

    cout<<"\nPreorder traversal is: \n";
    preorder(root);

    cout<<"\nPostorder traversal is: \n";
    postorder(root);*/
    return 0;
}