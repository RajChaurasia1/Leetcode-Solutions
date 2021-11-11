class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
   
        unordered_map<int,int>mp;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        int removed = 0;
        for(auto i : arr){
            mp[i]++;
        }
        
        
        for(auto i : mp){
            pq.push({i.second,i.first});
        }
        
        
        
        while(k > 0 && !pq.empty()){
            auto p = pq.top();
            pq.pop();
          
            if(p.first > k){
                p.first -= k;
                pq.push({p.first,p.second});
                break;
            }
            else{
                removed++;
                k -= p.first;
            }
           
        }
        
        return pq.size();
        
    }
};