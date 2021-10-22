class Solution {
public:
    int dp[2001];
    int pal[2001][2001];
    void isPalindrome(string &s){
        for(int g = 0; g < s.size(); g++){
            for(int i = 0, j = g; j < s.size(); i++, j++){
                if(g == 0)
                    pal[i][j] = true;
                else if(g == 1)
                    pal[i][j] = (s[i] == s[j]);
                else{
                    if((s[i] == s[j]) && (pal[i + 1][j - 1] == true))
                        pal[i][j] = true;
                    else
                        pal[i][j] = false;
                }
            }
        }
    }
    
    int solve(string &str, int i){
        if(i >= str.size() - 1) 
            return 0;
        if(pal[i][str.size() - 1]) 
            return dp[i]=0;
        if(dp[i] != -1)
            return dp[i];
        
        dp[i] = INT_MAX;
        for(int k = i; k < str.size() - 1; k++){
            if(pal[i][k]){
               dp[i] = min(dp[i], solve(str, k + 1) + 1); 
            }                
        }
        return dp[i];
    }
    
    int minCut(string str) {
        int n = str.size();
        memset(dp,-1,sizeof(dp));
        isPalindrome(str);
        return solve(str,0);
    }
};