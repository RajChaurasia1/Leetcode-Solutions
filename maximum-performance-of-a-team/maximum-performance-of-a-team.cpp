class Solution {
public:
    int mod = 1e9 + 7;
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
       long long int ans = 0, spd = 0;
        
        vector<pair<int,int>>v(n);
        
        for(int i = 0 ; i < n ; i++){
            v.push_back({efficiency[i],speed[i]});
        }
        
        sort(v.rbegin(),v.rend());
        
        priority_queue<int,vector<int>,greater<int>>pq;
        
        for(int i = 0 ; i < n ; i++){
            int eff = v[i].first;
            spd += v[i].second;
            
           
            
            if(pq.size() >= k){
                spd -= pq.top();
                pq.pop();
                pq.push(v[i].second);
            }
            else
                pq.push(v[i].second);
            
            ans = max(ans, spd*eff);
        }
        
        return ans%(mod);
    }
};