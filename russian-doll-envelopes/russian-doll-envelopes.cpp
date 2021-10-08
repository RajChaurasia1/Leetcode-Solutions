class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        
        sort(begin(envelopes),end(envelopes),[](vector<int>&a, vector<int>&b){
           if(a[0] == b[0])
               return a[1] < b[1];
            
            return a[0] < b[0];
            
        });
        
        int n = envelopes.size();
        
        vector<int>dp(n,1);
        
       
        for(int i = 1 ; i < n ; i++){
            for(int j = 0 ; j < i ; j++){
            if(envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1] && dp[i] < dp[j] + 1){
                
                dp[i] = dp[j] + 1;                
            }
        }
    }
        return *max_element(begin(dp),end(dp));
        
    }
};