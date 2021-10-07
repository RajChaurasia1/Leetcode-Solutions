class Solution {
public:
    int dp[366];
    
    int mincost(vector<int>&days, vector<int>&costs, int i){
        if(i >= days.size())
            return 0;

        
        if(dp[i]!=-1)
            return dp[i];
        
        
        int x = upper_bound(begin(days),end(days),days[i]) - begin(days);
        int y = upper_bound(begin(days),end(days),days[i] + 6) - begin(days);
        int z = upper_bound(begin(days),end(days),days[i] + 29) - begin(days);
        
        return dp[i] = min(costs[0] + mincost(days,costs,x),min(costs[1] + mincost(days,costs,y), costs[2] + mincost(days,costs,z)));
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(dp,-1,sizeof(dp));
       return mincost(days,costs,0);
        
        
    }
};