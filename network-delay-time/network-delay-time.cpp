class Solution {
public:
    

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        
        vector<pair<long int,long int>>adj[n + 1];
        vector<bool>vis(n+1,false);
        vector<long int>dist(n+1,INT_MAX);
        dist[k] = 0;
        priority_queue<pair<long int,long int>,vector<pair<long int,long int>>,greater<pair<long int, long int>>>pq;
        pq.push({0,k});
        for(int i = 0 ; i < times.size() ; i++){
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        
      long int ans = 0, cnt = 0;
      
        while(!pq.empty()){
            
            int sz = pq.size();
            while(sz--){
                auto p = pq.top();
             int u = pq.top().second;
             pq.pop();
            if(vis[u])
                continue;
            vis[u] = true;
            cnt++;
           ans = max(ans,p.first);
                for(auto x : adj[u]){
                    int v = x.first;
                    int wt = x.second;
                 
                     pq.push({wt + p.first,v});
                
                }
            }
        }
        
        return (cnt == n) ? ans : -1;
        
        
        
    }
};