class Solution {
public:

    int maxHeight(vector<vector<int>>& cuboids) {
        
        int n = cuboids.size();
        
      for(auto &v : cuboids){
          sort(begin(v),end(v));
      }
        
        sort(begin(cuboids),end(cuboids));
        
       int dp[n];
        
        for(int i = 0 ; i < n ; i++)
            dp[i] = cuboids[i][2];
     
        for(int i = 1 ; i < n ; i++){
            for(int j = 0 ; j < i ; j++){
                if(dp[i] < dp[j] + cuboids[i][2] && cuboids[i][0] >= cuboids[j][0] && cuboids[i][1] >= cuboids[j][1] && cuboids[i][2] >= cuboids[j][2]){
                    dp[i] = dp[j] + cuboids[i][2];
                }
            }
        }
        
        return *max_element(dp, dp + n);
        
    }
};