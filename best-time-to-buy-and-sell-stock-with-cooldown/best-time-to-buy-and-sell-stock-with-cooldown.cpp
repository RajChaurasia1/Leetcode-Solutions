class Solution {
public:
    
    int dp[5001][2];
    int profit(vector<int>&prices, int i, int status){
        if(i >= prices.size())
            return 0;
        
        if(dp[i][status] != -1)
            return dp[i][status];
        
        int donothing = profit(prices,i + 1, status);
        
        if(status){
            int sell = prices[i] + profit(prices,i + 2, 0);
            
            dp[i][status] = max(sell,donothing);
        }
        else{
            int buy = -prices[i] + profit(prices, i + 1, 1);
            
            dp[i][status] = max(donothing,buy);
        }
        
        return dp[i][status];
    }
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1)
            return 0;
        memset(dp,-1,sizeof(dp));
        int ans = profit(prices,0,0);
       return (ans > 0 ? ans : 0);
    }
};