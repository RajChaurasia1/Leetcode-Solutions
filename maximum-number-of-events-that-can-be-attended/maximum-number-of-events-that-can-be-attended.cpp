class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        
        int ans = 0;
        
        sort(begin(events),end(events),[](vector<int>&a,vector<int>&b){
           if(a[1] == b[1])
               return a[0] < b[0];
               
              return a[1] < b[1];
        });
        set<int>s;
        for(int i = 1 ; i <= events[events.size() - 1][1] ; i++){
            s.insert(i);
        }
        
        
     for(auto event : events){
         auto it = s.lower_bound(event[0]);
         
         if(it == s.end() || *it > event[1])
             continue;
         else{
             s.erase(it);
             ans++;
         }
     }
        
        
        return ans;
        
        
    }
};