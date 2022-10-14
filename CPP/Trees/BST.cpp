// Binary Search Tree (BST) in C++ : 
// yashsarnaik22 (code is modified and simplified version of code from Code-help by 
// babbar- YT)

#include<iostream>
#include<queue>
using namespace std;
class node{
    public: 
        int data;
        node* left;
        node* right;
    node(int d)
    {
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};
node* insertintoBST(node* &root, int d)
{
  //base case
  if(root==NULL){
      root= new node(d);
      return root;
  }  
  if(d>root->data){
      //right part me insert karna hai
      root->right=insertintoBST(root->right,d);
  }
  else{
      //left part me insert hoga
      root->left=insertintoBST(root->left,d);
  }
  return root;
}
void takeinput(node* &root)
{
    int data;
    cin>>data;

    while(data!=-1)
    {
        root= insertintoBST(root,data);
        cin>>data;
    }
}
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
bool searchinBST(node* root, int x) //search function
{    //O(H)
    node* temp=root;
    //base cases
    while(temp!=NULL){ 
        if(temp->data==x)
            return true;
        if(temp->data>x)
            temp=temp->left;
        else
            temp=temp->right;
    }
    return false;
    /*if(root==NULL)  //Aliter method O(logn)
        return false;
    
    if(root->data==x)
        return true;
    if(root->data>x){
        //left part me
        return searchinBST(root->left,x);
    }
    else{
        //right part me
        return searchinBST(root->right,x);
    }*/

}
node* minval(node* root)
{
    node* temp=root;
    while(temp->left!=NULL)
        temp=temp->left;
    
    return temp;
}
node* maxval(node* root)
{
    node* temp=root;
    while(temp->right!=NULL)
        temp=temp->right;

    return temp;
}
node* deletefromBST(node* root, int x)
{
    //base case
    if(root==NULL)
        return root;
    if(root->data==x){
        //0 child
        if(root->left == NULL && root->right == NULL){
            node *temp=root->left;
            delete root;
            return temp;
        }
        //1 child
        
        //left child
        if(root->left !=NULL && root->right == NULL)
        {
            node* temp= root->left;
            delete root;
            return temp;
        }
        //right child
        if(root->left == NULL && root->right != NULL){
            node* temp= root->right;
            delete root;
            return temp;
        }

        //2 child: either get minimum value from right
                // or maximum value from left
        if(root->left!= NULL && root->right!= NULL){
            int max = maxval(root->left)->data;
            root-> data = max;
            root->left = deletefromBST(root->left, max);
            return root;

        }
    }
    else if(root->data > x)
    {
        //left me jao
        root->left= deletefromBST(root->left, x);
        return root;
    } 
    else
    {
        //right me jao
        root->right= deletefromBST(root->right,x);
        return root;
    }
    
}
int main()
{
    node* root=NULL;
    int n;
    cout<<"enter data to create BST"<<endl;
    takeinput(root);
    cout<<"\nprinting the BST:\n";
    levelordertraversal(root);
    cout<<"\nprinting inorder traversal:\n";
    inorder(root);
    cout<<"\nprinting preorder traversal:\n";
    preorder(root);
    cout<<"\nprinting postorder traversal:\n";
    postorder(root);

    cout<<"\nenter the no. you want to search: ";
    cin>>n;
    cout<<"\nchecking presence of "<<n<<" in BST: "<<searchinBST(root,n);
    cout<<"\nMaximum value in BST is: "<<maxval(root)->data;
    cout<<"\nMinumum value in BST is: "<<minval(root)->data;

    root=deletefromBST(root, 14);
    levelordertraversal(root);
    cout<<"\nprinting inorder traversal:\n";
    inorder(root);
    cout<<"\nprinting preorder traversal:\n";
    preorder(root);
    cout<<"\nprinting postorder traversal:\n";
    postorder(root);
    return 0;
}