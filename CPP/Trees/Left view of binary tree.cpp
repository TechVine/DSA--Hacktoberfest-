void leftsideview(Node *root,int level,set<int>&s,vector<int>&ans)
{
    if(root == NULL) return;
    if(s.find(level)==s.end())
    {
        s.insert(level);
        ans.push_back(root->data);
    }
    
    leftsideview(root->left,level+1,s,ans);
    leftsideview(root->right,level+1,s,ans);
    return;
}
vector<int> leftView(Node *root)
{
   vector<int>ans;
   set<int>s;
   leftsideview(root,1,s,ans);
   return ans;
}
