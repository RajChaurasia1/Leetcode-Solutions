class Solution {
public:
    
    int pos_bouquet(vector<int>&bloomDay, int n,long long int d, int k){
        int kcnt = 0, mcnt = 0;
        for(int i = 0 ; i < n ; i++){
            if(d >= bloomDay[i]){
                kcnt++;
                
                if(kcnt == k){
                    mcnt++;
                    kcnt = 0;
                }
            }
                else{
                    kcnt = 0;
                }
            
        }
        
        return mcnt;
    }
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        
        int n = size(bloomDay);
        
        if(m*k > n)
            return -1;
        
        long long int l = INT_MAX, r = INT_MIN;
        
        for(int i = 0 ; i < n ; i++){
            l = min(l,(long long)bloomDay[i]);
            r = max(r,(long long)bloomDay[i]);
        }
        
        long long int ans = 0;
        
        while(l <= r){
            int mid = l + (r - l)/2;
            
            if(pos_bouquet(bloomDay,n,mid,k) >= m){
                ans = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        
        return ans;
        
    }
};