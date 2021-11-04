class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char,int>mp;
        
        for(auto c : s){
            mp[c]++;
        }
        
        int ans = 0;
        priority_queue<pair<int,char>>pq;
        for(auto i : mp){
            pq.push({i.second,i.first});
        }
        
        
        while(!pq.empty()){
            
            auto p = pq.top();
            pq.pop();
            
            if(!pq.empty() && pq.top().first == p.first){
                ++ans;
                
                --p.first;
                
                if(p.first > 0){
                    pq.push({p.first,p.second});
                }
                
            }
            
            
        }
        
        return ans;
        
    }
};