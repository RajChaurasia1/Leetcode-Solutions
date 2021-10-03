class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        
        int dp[n + 1][m + 1];
        
        for(int i = 0 ; i < n + 1 ; i++){
            for(int j = 0 ; j < m + 1 ; j++){
                if(i == 0 || j == 0)
                    dp[i][j] = 0;
                else{
                    if(word1[i - 1] == word2[j - 1])
                        dp[i][j] = 1 + dp[i - 1][j - 1];
                    else
                        dp[i][j] = max(dp[i -1][j], dp[i][j - 1]);
                }
            }
        }
        
        return n + m - 2*dp[n][m];
        
    }
};