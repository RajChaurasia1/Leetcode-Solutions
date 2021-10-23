class Solution {
public:
    
    int dp[21][31];
    bool regx(string s, string p, int i, int j){
        if(i >= s.size() && j >= p.size())
            return true;
        if(j >= p.size())
            return false;
        if(dp[i][j] != -1)
            return dp[i][j];
        
        bool match = (i < s.size() && (s[i] == p[j] || p[j] == '.'));
        if(j + 1 < p.size() && p[j + 1] == '*'){
            bool ans = (regx(s, p, i, j + 2) || (match && regx(s, p, i + 1, j)));
            return dp[i][j] = ans;
        }
        
        if(match)
            return dp[i][j] = regx(s, p, i + 1, j + 1);
        
        return dp[i][j] = false;
    }
    
    
    bool isMatch(string s, string p) {
       memset(dp,-1,sizeof(dp));
       return regx(s,p,0,0);
        
        
    }
};