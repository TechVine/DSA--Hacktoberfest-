class Solution {
public:
    double dfs(string a,string&b,unordered_map<string,unordered_map<string,double>>graph,unordered_set<string>&visited)
    {
        
    if(graph[a].find(b)!=graph[a].end())
    {
       return graph[a][b]; 
    }
for(auto node :graph[a])
    {
        if(visited.find(node.first)==visited.end())
        {
            visited.insert(node.first);
            double val=dfs(node.first,b,graph,visited);
            if(val)
            {
                graph[a][b]=node.second*val;
                return graph[a][b];
            }
        }
    }
        return 0;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
       vector<double>ans;
       unordered_map<string,unordered_map<string,double>>graph;
       for(int i=0;i<equations.size();i++)
       {
           graph[equations[i][0]][equations[i][1]]=values[i];
           graph[equations[i][1]][equations[i][0]]=(double) 1/(values[i]);
       }
       for(int i=0;i<queries.size();i++)
       {
           unordered_set<string>visited;
           double val=dfs(queries[i][0],queries[i][1],graph,visited);
           if(!val)
           {
               ans.push_back(-1.0);
           }
           else
           {
               ans.push_back(val);
           }
       }
        return ans;
    }
};