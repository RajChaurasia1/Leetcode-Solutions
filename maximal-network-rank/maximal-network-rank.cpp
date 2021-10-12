class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int>adj[n];
        vector<vector<int>>ed(n,vector<int>(n,0));
        int ans = 0;
        
        
        
        for(auto road : roads){
            adj[road[0]].push_back(road[1]);
            adj[road[1]].push_back(road[0]);
            
            ed[road[0]][road[1]]++,ed[road[1]][road[0]]++;
        }
        
        
        for(int i = 0 ; i < n ; i++){
            for(int j = i + 1 ; j < n ; j++){
                int tot = adj[i].size() + adj[j].size() - ed[i][j];
              
                ans = max(ans,tot);
            }
        }
        
        return ans;
    }
};