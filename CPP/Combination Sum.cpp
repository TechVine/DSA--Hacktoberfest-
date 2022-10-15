class Solution {
public:
    vector<vector<int>>ans;  
    void findways(int index,vector<int>&v,vector<int>& candidates, int target,int currsum)
    {
      if(currsum>target)
      {
          return;
      }
      if(target==currsum)
      {
          ans.push_back(v);
          return;
      }
     for(int i=index;i<candidates.size();i++)
     {
         v.push_back(candidates[i]);
         findways(i,v,candidates,target,currsum+candidates[i]);
         v.pop_back();
     }
    
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int currsum=0;
        vector<int>v;
        findways(0,v,candidates,target,currsum);
        return ans;
    }
};