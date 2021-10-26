class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n = trips.size();
        
        
        sort(begin(trips),end(trips),[](vector<int>&a,vector<int>&b){
            if(a[1] == b[1])
                return a[2] < b[2];
           return a[1] < b[1]; 
        });
        
        for(auto x : trips)
            cout << x[0] << " " << x[1] << " " << x[2] << endl;
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        int cap = trips[0][0];
        pq.push({trips[0][2],0});
        for(int i = 1 ; i < n ; i++){
           if(cap <= capacity){
                while(!pq.empty()){
                    if(trips[i][1] >= pq.top().first){
                        cap -= trips[pq.top().second][0];
                        pq.pop();
                    }
                    else
                        break;
                }
            cap += trips[i][0];
            if(cap <= capacity){
                pq.push({trips[i][2],i});
            }
            else 
                return false;
           }
            else
                return false;
        }
        
        if(cap <= capacity)
            return true;
        return false;
    
    
    }
    
};