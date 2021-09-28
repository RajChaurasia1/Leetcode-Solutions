class Solution {
public:
    
    int dp[601][101][101];
    unordered_map<int,vector<int>>mp;
    int sz;
    int oz(int i, int m, int n){
         if(m < 0 || n < 0 || m == 0 && n == 0 || i >= sz) 
             return 0;
         if(dp[i][m][n]!=-1) 
             return dp[i][m][n];
        
        int zeroes = mp[i][0], ones = mp[i][1];
        int a = -1, b = -1;
        
        if(m >= zeroes && n >= ones)
            a = max(oz(i + 1, m, n), 1 + oz(i + 1, m - zeroes, n - ones));
        else
            b = oz(i + 1, m, n);
        
        return dp[i][m][n] = max(a,b);
            
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp,-1,sizeof(dp));        
      
        sz = strs.size();
        
        for(int i = 0 ; i < sz ; i++){
            int z = 0, o = 0;
            for(auto c : strs[i]){
                if(c == '0')
                    z++;
                else
                    o++;
            }
            mp[i].push_back(z);
            mp[i].push_back(o);
            
           
        }
        
        
        return oz(0,m,n);
    }
};