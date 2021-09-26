class Solution {
public:
    
    int dp[50001];
    int vis[50001];
    int n;
    bool end(vector<int>&arr, int i){
        if(i < 0 || i >= n || vis[i] == 1)
            return 0;
        if(arr[i] == 0)
            return 1;
        if(dp[i] != -1)
            return dp[i];
        
        vis[i] = 1;
        int f = 0;
        f = end(arr,i - arr[i]) || end(arr,i + arr[i]);
        vis[i] = 0;
        return dp[i] = f;
        
    }
    
    bool canReach(vector<int>& arr, int start) {
        n = arr.size();
        memset(dp,-1,sizeof(dp));
        memset(vis,0,sizeof(vis));
        return end(arr,start);
    }
};