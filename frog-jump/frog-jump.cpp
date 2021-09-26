class Solution {
public:
    int n ;
    int dp[2001][2001];
    bool end(vector<int>&stones, int i, int k){
  
        // if(stones[n - 1] == stones[i] + k)
        //     return true;
        if(i==n-1) return true;
        if(k == 0)
            return false;
        if(dp[i][k]!=-1)
            return dp[i][k];
        
        bool ans = false;
        for(int j = i + 1 ; j < n ; j++){
             
            if(stones[j] == stones[i] + k - 1)
                ans = ans || end(stones, j, k -  1);
            if(stones[j] == stones[i] + k)
                ans = ans || end(stones, j, k);
            if(stones[j] == stones[i] + k + 1)
                ans = ans || end(stones, j, k +  1);
        
        }
        
       return dp[i][k] = ans;
    }
    bool canCross(vector<int>& stones){
        n = size(stones);
        memset(dp,-1,sizeof(dp));
        if(n >= 2 && stones[1]!=1)
            return false;
        else if(n == 2 && stones[1] == 1)
            return true;
        
        return end(stones,1,1);
    }
};