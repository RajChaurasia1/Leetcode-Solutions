class Solution {
public :
    
    int dfs(int u, vector<int>adj[], vector<bool>&vis, vector<bool>&hasApple){
        vis[u] = true;
        
        int apple = 0;
        
        for(auto v : adj[u]){
            if(!vis[v])
                apple += dfs(v,adj,vis,hasApple);
        }
        
        if(u == 0)
            return apple;
        return apple + ((hasApple[u] || apple > 0) ? 2 : 0);
    }
    
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        
        vector<int>adj[n];
        vector<bool>vis(n,false);
        
        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
            
        }
        
        return dfs(0,adj,vis,hasApple);
        
        
    }
};