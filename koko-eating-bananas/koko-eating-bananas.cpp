class Solution {
public:
    int hours(vector<int>&piles, int mid){
        int hour = 0;
        for(int i = 0 ; i < piles.size() ; i++){
            int time = (piles[i] + mid - 1)/mid;
            
            hour += time;
            
        }
        
        return hour;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(begin(piles),end(piles));
        int l = 1, r = INT_MIN, ans = 0;
        for(int i = 0 ; i < piles.size() ; i++){
            if(r < piles[i])
                r = piles[i];
        }
        
        while(l <= r){
            int mid = l + (r - l)/2;
            
            if(hours(piles,mid) <= h){
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