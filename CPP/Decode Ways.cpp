class Solution {
public:
    int find(int i,string s,vector<int>&dp)
    {
        if(s[i]=='0')
        {
            return 0;
        }
        if(i==s.size())
        {
            return 1;
        }
        if(dp[i]!=-1)
        {
            return dp[i];
        }
        int one = find(i+1,s,dp);
        int two=0;
        if(i < s.size() -1 && (s[i] == '1' || s[i] == '2' && s[i+1] <= '6'))
           {
           two+=find(i+2,s,dp);
           }
           return dp[i] = one+two;
    }
    int numDecodings(string s) {
    vector<int>dp(s.size()+1,-1);
    return find(0,s,dp);
    
    }
};