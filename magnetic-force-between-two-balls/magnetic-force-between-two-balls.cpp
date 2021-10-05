class Solution {
public:
    
    int pos(vector<int>&position, int d){
        int cnt = 1, x = 0;
        
        for(int i = 1 ; i < position.size() ; i++){
            if(position[i] - position[x] >= d){
                cnt++;
                x = i;
            }
        }
        
        return cnt;
        
    }
    
    
    int maxDistance(vector<int>& position, int m) {
        int n = size(position),  ans = 0;
        sort(begin(position), end(position));
        int l = 1, r = position[n - 1] - position[0];
        
        
        while(l <= r){
            int mid = l + (r - l)/2;
            
            if(pos(position,mid) >= m){
                ans = mid;
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
            
        }
        return ans;
    }
};