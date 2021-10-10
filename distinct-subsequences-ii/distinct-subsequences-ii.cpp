class Solution {
public:
    int mod = 1e9 + 7;
    int distinctSubseqII(string s) {
        
        int n = s.size();
        
        long long int dp[n + 1];
        map<char,int>m;
        
        dp[0] = 1;
        for(int i = 1 ; i < n + 1 ; i++){
            dp[i] = (dp[i - 1]*2)%mod;
            
            
            
            if(m.find(s[i - 1]) != m.end()){
                  dp[i] -= dp[m[s[i - 1]] - 1];
            }
            dp[i]%=mod;
            m[s[i - 1]] = i;
            
            
        }
         dp[n]--;
     
        if(dp[n] < 0)
            dp[n]+=mod;
        
        return dp[n];
        
    }
};