class Solution {
public:
    
    unordered_map<long int,long int>mp;
    
    int findmin(int n){
        if(mp.find(n) != mp.end())
            return mp[n];
        int ans = INT_MAX;
        if(n%2 == 0)
            ans = min(ans,findmin(n/2));
        if(n%3 == 0)
            ans = min(ans,findmin(n/3));
        
        if(n%2 != 0 || n%3 != 0)
            ans = min(ans,findmin(n - 1));
        
        return mp[n] = 1 + ans;
            
    }
    
    
    int minDays(int n) {
        mp[0] = 0, mp[1] = 1;
        
        return findmin(n);
        
    }
};