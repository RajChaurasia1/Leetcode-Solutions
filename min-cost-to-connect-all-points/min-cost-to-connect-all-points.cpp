class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        int n = points.size();
        vector<pair<int,int>>adj[n];
        for(int i = 0; i < n ; i++){
            for(int j = i + 1 ; j < n ; j++){
            
                adj[i].push_back({j,abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1])});
                adj[j].push_back({i,abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1])});
            }
        }
        
        vector<bool>mst(n, false);
        vector<int>key(n,INT_MAX);
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        pq.push({0,0});
        key[0] = 0;
        
        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();
            
            int u = p.second;
            
            if(mst[u])
                continue;
            mst[u] = true;
            
            for(auto x : adj[u]){
                int v = x.first;
                int wt = x.second;
                
                if(!mst[v] && wt < key[v]){
                    key[v] = wt;
                    pq.push({key[v],v});
                }
            }
            
        }
        
        int ans = 0;
        
        for(auto keys : key)
            ans += keys;
        
        return ans;
    }
};