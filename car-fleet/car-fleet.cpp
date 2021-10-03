class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
       int ans = 1;
        int n = position.size();
        if(position.size() == 1)
            return 1;
        
        vector<pair<int,int>>car(n);
        
        for(int i = 0 ; i < n ; i++){
            car[i].first = position[i];
            car[i].second = speed[i];
        }
       sort(begin(car),end(car),[&](pair<int,int>&a,pair<int,int>&b){
          if(a.first == b.first)
              return a.second >= b.second;
           return a.first >= b.first;
       });
       
        double prev_t = (double)(target - car[0].first)/car[0].second;
        for(int i = 1 ; i < n; i++){
            double t = (double)(target - car[i].first)/car[i].second;
            if(prev_t >= t){
                
                continue;
            }
            else{
                prev_t = t;
                ans++;}
        }
        
        
        
        return ans;
            
    }
};