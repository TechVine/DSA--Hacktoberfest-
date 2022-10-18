/**

 * Definition for a binary tree node.

 * struct TreeNode {

 *     int val;

 *     TreeNode *left;

 *     TreeNode *right;

 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}

 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

 * };

 */

class Solution {

public:

    bool flag = false;

    void dfs(TreeNode* root, int targetSum,int sum)

    {

        if(!root)

        {

            return;

        }

      sum+=root->val;

      if(sum==targetSum && !root->left && !root->right)

      {

          flag = true;

          return;

      }

      dfs(root->left,targetSum,sum);

      dfs(root->right,targetSum,sum);

    }

    bool hasPathSum(TreeNode* root, int targetSum) {

        int sum =0;

        dfs(root,targetSum,sum);

        return flag;

    }

};

Footer

© 2022 GitHub, Inc.

Footer navigation

