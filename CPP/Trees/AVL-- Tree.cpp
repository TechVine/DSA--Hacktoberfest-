/* Node is as follows:

struct Node
{
	int data, height;
	Node *left, *right;
	Node(int x)
	{
		data = x;
		height = 1;
		left = right = NULL;
	}
};

*/
#include <iostream>
using namespace std;
void inorder(vector<int>&v,Node*root,int data){
    if(root){
        inorder(v,root->left,data);
        if(root->data!=data){
            v.push_back(root->data);
        }
        inorder(v,root->right,data);
        
    }
}
Node* buildtree(vector<int>&v,int s,int e){
    if(s>e){
        return NULL;
    }
    int mid=(s+e)/2;
    Node* root=new Node(v[mid]);
    root->left=buildtree(v,s,mid-1);
    root->right=buildtree(v,mid+1,e);
    return root;
}
Node* deleteNode(Node* root, int data)
{
    vector<int>v;
    inorder(v,root,data);
    return buildtree(v,0,v.size()-1);
    //add code here,
}
