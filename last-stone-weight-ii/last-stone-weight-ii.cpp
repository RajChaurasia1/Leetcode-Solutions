class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0, n = stones.size(), ans = INT_MAX;
        for(auto stone : stones){
            sum += stone;
        }
        
        
        int dp[n + 1][sum + 1];
        
        for(int i = 0 ; i < n + 1 ; i++)
            dp[i][0] = 1;
        
        for(int i = 1 ; i < sum + 1 ; i++)
            dp[0][i] = 0;
        
        for(int i = 1 ; i < n + 1 ; i++){
            for(int j = 1 ; j < sum + 1 ; j++){
                if(j >= stones[i - 1])
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - stones[i - 1]];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        
        vector<int>v;
        
        for(int i = 0 ; i <= sum/2 ; i++){
            if(dp[n][i])
                v.push_back(i);
        }
        
        for(int i = 0 ; i < v.size() ; i++)
            ans = min(ans, sum - 2*v[i]);
        
        
        return ans;
    
    }
};