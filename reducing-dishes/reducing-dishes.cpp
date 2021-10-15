class Solution {
public:
    
    int dp[501][501];
    
    int ltc(vector<int>&satisfaction, int i, int t){
        if(i >= satisfaction.size())
            return 0;
        
        if(dp[i][t] != -1)
            return dp[i][t];
        
        return dp[i][t] = max(satisfaction[i]*t + ltc(satisfaction,i + 1, t + 1), ltc(satisfaction, i + 1, t)); 
    }
    
    
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(begin(satisfaction),end(satisfaction));
        memset(dp,-1,sizeof(dp));
        
        return max(0,ltc(satisfaction,0,1));
        
    }
};