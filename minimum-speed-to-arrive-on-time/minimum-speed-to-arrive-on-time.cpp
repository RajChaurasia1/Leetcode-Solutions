class Solution {
public:
    double possible(vector<int>&dist, int mid){
        int hrs = 0;
        
        for(int i = 0 ; i < dist.size() - 1 ; i++){
            hrs += (dist[i] + mid - 1)/mid;
        }
        
        double hours = (double)hrs + (double)(dist[dist.size() - 1])/(double)mid;
        
        return hours;
    }
    
    
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int l = 1, r = 10000000, ans;
        
        while(l <= r){
            int mid = l + (r - l)/2;
            
            if(possible(dist,mid) <= hour){
                ans = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        if(possible(dist,ans) <= hour)
        return ans;
        return -1;
    }
};