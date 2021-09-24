class Solution {
public:
    
    //unordered_map<string,int>mp;
    int dp[100001][2][3];
    int profit(vector<int>&prices, int i, int status, int k){
        
        if(i >= prices.size() || k == 0)
            return 0;
        //string key = to_string(i) + "_" + to_string(status) + "_" + to_string(k);
        // if(mp.find(key) != mp.end())
        //     return mp[key];
        if(dp[i][status][k]!=-1)
            return dp[i][status][k];
        
        int ans = 0;
        if(status == 0){
            int buy = profit(prices,i+1,1,k) - prices[i];
            int nobuy = profit(prices,i+1,0,k);
            ans = max(buy,nobuy);
        }
        else{
            int sell = profit(prices,i+1,0,k-1) + prices[i];
            int nosell = profit(prices,i+1,1,k);
            ans = max(sell,nosell);
        }
        // return mp[key] = ans;
        return dp[i][status][k] = ans;
    }
    
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
       return profit(prices,0,0,2);
    }
};