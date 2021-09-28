class Solution {
public:
 
    string frequencySort(string s) {
        map<char,int>mp;
        for(auto c : s){
            mp[c]++;
        }
        priority_queue<pair<int,char>>pq;
        for(auto c : s){
            pq.push({mp[c],c});
        }
        string ans="";
        while(!pq.empty()){
            ans+=pq.top().second;
            pq.pop();
        }
        
        return ans;
        
    }
};