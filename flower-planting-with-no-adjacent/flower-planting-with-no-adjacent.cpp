class Solution {
public:
 bool issafe(int i, int k, vector<int>&color, vector<int>adj[])
     {
       for(int l = 0; l < adj[i].size(); l++)
          if(color[adj[i][l]] == k)
              return false;
     
       return true;
     
    }
    bool solve(int i, int n, vector<int>&color, vector<int>adj[])
    {
        if(i == n + 1) 
            return true;
        
        for(int k = 1; k <= 4; k++)
        {
            if(issafe(i,k,color,adj))
            {
               color[i] = k;
               if(solve(i + 1,n,color,adj)) 
                   return true;
            }
        }
        
        color[i] = -1;
        
        return false;
    }
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        
        vector<int>adj[n + 1];
        
        for(auto path : paths){
            adj[path[0]].push_back(path[1]);
            adj[path[1]].push_back(path[0]);
        }
        
        vector<int>color(n + 1, 0);
        
        solve(1, n, color, adj);
        
        vector<int>ans(color.begin() + 1, color.end());
        return ans;
    }
};