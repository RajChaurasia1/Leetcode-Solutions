class Solution {
public:

    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int>mp;
        vector<pair<int,string>>pq;
        
        for(auto s : words)
            mp[s]++;
        
        for(auto x : mp){
            pq.push_back({x.second,x.first});
        }
        sort(begin(pq),end(pq),[](pair<int,string>&a,pair<int,string>&b){
              if(a.first == b.first)
            return a.second < b.second;
        return a.first > b.first;
        });
        vector<string>ans;
    
        for(int i = 0 ; i < k ; i++){
            ans.push_back(pq[i].second);
           
        }
        return ans;
    }
};