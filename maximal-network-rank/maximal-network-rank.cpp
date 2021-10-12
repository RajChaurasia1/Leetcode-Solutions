class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int>adj[n];
        int ans = 0;
        
        for(auto road : roads){
            adj[road[0]].push_back(road[1]);
            adj[road[1]].push_back(road[0]);
        }
        
        
        for(int i = 0 ; i < n ; i++){
            for(int j = i + 1 ; j < n ; j++){
                int tot = adj[i].size() + adj[j].size();
                for(auto v : adj[j]){
                    if(v == i){
                        --tot;
                        break;
                    }
                }
                ans = max(ans,tot);
            }
        }
        
        return ans;
    }
};