class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        int n = size(cost), ans = 0, mx = -1, sum = 0;
        for(int i = 0 ; i < n ; i++){
            int j = i;
            sum = cost[j];
            mx = sum;
            while(j + 1 < n && s[j] == s[j + 1]){
                sum+=cost[j + 1];
                mx = max(cost[j + 1],mx);
                ++j;
            }
            
            if(sum > cost[i]){
                ans += (sum - mx);
            }
            i = j;
        }
        
        return ans;
    }
};