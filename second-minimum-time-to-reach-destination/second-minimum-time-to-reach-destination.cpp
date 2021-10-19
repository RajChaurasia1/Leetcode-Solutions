class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        
        vector<int>adj[n + 1];
        
        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
    
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>dist(n + 1, INT_MAX); 
        vector<int>freq(n + 1, 0);
        pq.push({0,1});
        
        int f = 0;
        freq[1] = 1;
        dist[1] = 0;
        while(!pq.empty()){

                pair<int,int>p = pq.top();
                pq.pop();
                
                int u = p.second;
                int curr_time = p.first;
            
                int signal = curr_time/change;
                if(signal % 2 != 0)
                    curr_time += ((change*(signal + 1)) - curr_time);
            
                for(auto v : adj[u]){
                    if((dist[v] != (curr_time + time)) && freq[v] < 2){
                        if(v == n && f == 1){
                            return (curr_time + time); 
                        }
                        if(v == n){
                            f = 1;
                        }
                        
                        dist[v] = curr_time + time;
                        freq[v]++;
                        pq.push({dist[v],v});
                    }
                }
        }
        
        return -1;
        
    }
};