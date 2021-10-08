class Solution {
public:
    
     int dp[4][500001];
   int solve(vector<int>& obstacles,int currLane,int i){
        if(i == obstacles.size() - 1) 
            return 0;
        if(currLane == obstacles[i]) 
            return INT_MAX - 1;
        if(dp[currLane][i] != -1) 
            return dp[currLane][i];
       
        int lane1, lane2;
       
        if(obstacles[i + 1] == currLane){
            if(currLane == 1){
                lane1 = 2;
                lane2 = 3;
            }
            else if(currLane == 2){
                lane1 = 1;
                lane2 = 3;
            }
            else{
                lane1 = 2;
                lane2 = 1;
            }
             return dp[currLane][i] =  1 + min(solve(obstacles,lane1,i),solve(obstacles,lane2,i));
        }
        else 
            return dp[currLane][i]=solve(obstacles,currLane,i+1);
             
    }
    
    int minSideJumps(vector<int>& obstacles) {
        memset(dp,-1,sizeof(dp));
        return solve(obstacles,2,0);
        
    }
};