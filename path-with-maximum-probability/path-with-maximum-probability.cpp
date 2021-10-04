class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        
        int sz = size(edges);
        
        vector<pair<int,double>>adj[n];
        
        for(int i = 0 ; i < sz ; i++){
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        
        priority_queue<pair<double,int>>pq;
        vector<double>prob(n,0);
       prob[start] = 1.0;
        pq.push({(double)1,start});
        vector<bool>vis(n,false);
        double ans = 0;
        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();
            int u = p.second;
          
            if(vis[u])
                continue;
            vis[u] = true;
           
            //cout << u << " " << p.first << endl;
            if(u == end)
                return p.first;
            for(auto v : adj[u]){
                int x = v.first;
                double sprob = v.second;
                if(prob[x] <= prob[u]*sprob){
                  //  cout << " x " << x << " " << prob[u]*sprob << endl;

                    prob[x] = prob[u]*sprob;
                    pq.push({prob[x],x});
                }
                
            }
        }
        return ans;
    }
};