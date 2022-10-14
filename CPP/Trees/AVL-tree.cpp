//AVL tree in C++
//AVL tree
#include<iostream>
#include<queue>
using namespace std;
class node
{
	public:
		int data;
		node *left;
		node *right;
	node(int d){
		this->data=d;
		this->left=NULL;
		this->right=NULL;
	}
};

class AVL
{
	public:
		node *root;
		int height(node *root);
		int diff(node *root);
		node *RR(node *root);
		node *LL(node *root);
		node *LR(node *root);
		node *RL(node *root);
		node *balance(node *root);
		node *insertintoAVL(node* root, int data);
		void display(node *root);
		AVL(){
			root=NULL;
		}
};
void takeinput(node* &root)
{   AVL a;
    int data;
    cin>>data;

    while(data!=-1)
    {
        root= a.insertintoAVL(root,data);
        cin>>data;
    }
}
node *AVL::insertintoAVL(node* root, int data){
	if(root==NULL)
	{
		root= new node(data);
		return root;
	}
	else{
		if(data < root->data)
	{
		root->left= insertintoAVL(root->left, data);
		root=balance(root);
	}
	else if(data > root->data)
	{
		root->right=insertintoAVL(root->right, data);
		root=balance(root);
	}
	else{
		cout<<"\n node already exists!";
		return root;
	}
	}
}
node *AVL::balance(node *temp){
 int bal_factor=diff(temp);
 if(bal_factor>1)
 {
 	if(diff(temp->left)>0)
 		temp=RR(temp);
 	else
 		temp=LR(temp);
 }
 else if(bal_factor <-1)
 {
 	if (diff(temp->right)>0)
 		temp=RL(temp);
 	else
 		temp=LR(temp);
 }
 return temp;
}

int AVL::diff(node *temp){
	int lheight=height(temp->left);
	int rheight=height(temp->right);
	int b_factor= lheight-rheight;
	return b_factor;
}
int AVL::height(node* temp){
	int h=0;
	if(temp!=NULL){
		int lheight=height(temp->left);
		int rheight=height(temp->right);
		int max_height= max(lheight, rheight);
		h=max_height+1; 
	}
	return h;
}
node *AVL::LL(node *parent){
	node *temp;
	temp=parent->left;
	parent->left=temp->right;
	temp->right=parent;
	return temp;
}
node *AVL::RR(node *parent)
{
	node *temp;
	temp= parent->right;
	parent->right=temp->left;
	temp->left=parent;
	return temp;
}
node *AVL::RL(node *parent){
	node *temp;
	temp-parent->right;
	parent->right=LL(temp);
	return RR(parent);
}
node *AVL::LR(node *parent){
	node *temp;
	temp=parent->left;
	parent->left=RR(temp);
	return LR(parent);
}
node* levelordertraversal(node* root)
{
	queue<node*>q;
	q.push(root);
	q.push(NULL);
	while(!q.empty()){
		node* temp= q.front();
		q.pop();
		if(temp==NULL){
			cout<<endl;
			if(!q.empty()){
				q.push(NULL);
			}
		}
		else{
			cout<<temp->data<<" ";
			if(temp->left){
				q.push(temp->left);
			}
			if(temp->right)
			{
				q.push(temp->right);
			}
		}
	}
}
int main(){
	int ch, x;
	AVL a;
	node* root = NULL;
	cout<<"insert data: ";
	takeinput(root);
	cout<<"\nprinting AVL tree:\n";
	levelordertraversal(root);
return 0;
}
