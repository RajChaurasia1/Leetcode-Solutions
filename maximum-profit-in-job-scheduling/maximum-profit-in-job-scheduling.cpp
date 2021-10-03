class Solution {
public:
    
    struct job{
      int start;
      int end;
      int profit;
    };
    
    static bool cmp(job &a, job &b){
        return a.end < b.end;
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        job a[n];
        for(int i = 0 ; i < n ; i++){
            a[i].start = startTime[i];
            a[i].end = endTime[i];
            a[i].profit = profit[i];
        }
        
        sort(a,a+n,cmp);
        int dp[n];
        
        dp[0] = a[0].profit;
        
        for(int i = 1 ; i < n ; i++){
            int inc = a[i].profit;
            int lid = -1;
            for(int j = i - 1 ; j >= 0 ; j--){
                if(a[j].end <= a[i].start){
                    lid = j;
                    break;
                }
            }
            if(lid!=-1){
                inc+=dp[lid];
            }
            dp[i] = max(inc,dp[i-1]);
            
            
        }
        return dp[n-1];
        
        
        
    }
};