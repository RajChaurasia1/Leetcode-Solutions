class Solution {
public:
    
    int dp[1001][1001];
    int mindiff(vector<int>&pr, int i, int j){
        if(i > j)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
       // int leftsum = (i == 0) ? 0 : pr[i - 1];
        return dp[i][j] = max(pr[j + 1] - pr[i + 1] - mindiff(pr,i + 1, j), pr[j] - pr[i] - mindiff(pr,i, j - 1));
        
      
        
    }
    int stoneGameVII(vector<int>& stones) {
        memset(dp,-1,sizeof(dp));
        int n = stones.size();  
        vector<int>pr(n + 1, 0);
        //pr[0] = stones[0];
        for(int i = 0 ; i < n ; i++){
            pr[i + 1] = pr[i] + stones[i];
        }
        
       return mindiff(pr,0,n - 1);
        
    }
};