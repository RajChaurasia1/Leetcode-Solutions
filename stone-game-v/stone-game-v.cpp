class Solution {
public:
    
    int dp[501][501];
    int maxstone(vector<int>&pr, int s, int e){
        if(s > e)
            return 0;
        if(dp[s][e] != -1)
            return dp[s][e];
        int left = (s == 0)?0:pr[s - 1];
        int ans = 0;
        for(int i = s ; i < e ; i++){
            int l = pr[i] - left;
            int r = pr[e] - pr[i];
            
            if(l < r){
                ans = max(ans,l + maxstone(pr,s,i));
            }
            else if(l > r){
                ans = max(ans,r + maxstone(pr,i + 1, e));
            }
            else{
                ans = max(ans,max(l + maxstone(pr,s,i), l + maxstone(pr,i + 1, e)));
            }
        }
        
        return dp[s][e] = ans;
    }
    
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int>pr(n);
        memset(dp,-1,sizeof(dp));
        pr[0] = stoneValue[0];
        
        for(int i = 1 ; i < n ; i++){
            pr[i] = pr[i - 1] + stoneValue[i];
        }
        
       return maxstone(pr,0,n - 1);
        
    }
};