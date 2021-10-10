class Solution {
public:
    int sz;
    int dp[101][101];
    int cost(int cut_start, int cut_end, vector<int>&cuts, int start, int end){
        if(cut_start >= cut_end)
            return 0;
        
        if(dp[cut_start][cut_end] != -1)
            return dp[cut_start][cut_end];
        
        int ans = INT_MAX;
        
        for(int i = cut_start ; i < cut_end ; i++){
            ans = min(ans, end - start + cost(cut_start, i, cuts, start, cuts[i]) + cost(i + 1, cut_end, cuts, cuts[i], end));
        }
                      
          return dp[cut_start][cut_end] = ans;
    }
    int minCost(int n, vector<int>& cuts) {
        sz = cuts.size();
        sort(begin(cuts),end(cuts));
        memset(dp,-1,sizeof(dp));
        return cost(0,sz,cuts,0,n);
        
        
        
    }
};