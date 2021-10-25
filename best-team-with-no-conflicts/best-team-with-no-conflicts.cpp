class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        
        vector<vector<int>>v(scores.size(),vector<int>(2));
        vector<int>dp(scores.size());
        for(int i = 0 ; i < scores.size() ; i++){
            v[i][1] = scores[i], v[i][0] = ages[i]; 
        }
        
        sort(begin(v),end(v));
        
        int ans = 0;
        
        for(int i = 0 ; i < scores.size() ; i++){
            dp[i] = v[i][1];
            for(int j = 0 ; j < i ; j++){
                if(v[i][1] >= v[j][1] && v[i][0] >= v[j][0]){
                    dp[i] = max(dp[i],dp[j] + v[i][1]);
                }
            }
            
            ans = max(ans, dp[i]);
        }
        
        
        return ans;
        
        
    }
};