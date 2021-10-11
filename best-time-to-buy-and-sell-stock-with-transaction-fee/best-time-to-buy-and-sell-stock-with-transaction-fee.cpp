class Solution {
public:
    int dp[50001][2]; 
    int profit(int i, int status, vector<int>&prices, int fee){
        if(i >= prices.size())
            return 0;
        
        if(dp[i][status] != -1)
            return dp[i][status];
        
        int a = profit(i + 1, status, prices, fee),b;
        
        if(status){
            b = prices[i] - fee + profit(i + 1, 0, prices, fee);
        }
        else{
            b = -prices[i] + profit(i + 1, 1, prices, fee);
        }
        
        return dp[i][status] = max(a,b);
    }
    int maxProfit(vector<int>& prices, int fee) {
      
        memset(dp,-1,sizeof(dp));
        
        return profit(0,0,prices,fee);
        
    }
};