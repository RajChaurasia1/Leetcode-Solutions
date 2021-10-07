class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
       
        vector<int>adj[n];
        int ans = 0;
        for(int i = 0 ; i < manager.size() ; i++){
            if(manager[i]!=-1)
            adj[manager[i]].push_back(i);
        }
        
        queue<pair<int,int>>q;
        q.push({headID,0});
        ans = INT_MIN;
        vector<bool>vis(n,false);
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto p = q.front();
                q.pop();
                
                
                int u = p.first;
                int t = p.second;
                ans = max(ans,t);
                if(vis[u])
                    continue;
                vis[u] = true;
                
                for(auto v : adj[u]){
                    
                    q.push({v,t + informTime[u]});

                }
            }
        }
        
        
        return ans;
    }
};