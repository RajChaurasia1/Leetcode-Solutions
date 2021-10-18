class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
   
        intervals.push_back(newInterval);
        vector<vector<int>>ans(10002,vector<int>(2,0));
        
        sort(intervals.begin(),intervals.end());
        
        ans[0][0] = intervals[0][0];
        ans[0][1] = intervals[0][1];
     
        int j = 0, cnt = 1;
        for(int i = 1; i < intervals.size() ; i++){
            if(ans[j][1] < intervals[i][0]){
               
                ++j;
                ans[j][0] = intervals[i][0];
                ans[j][1] = intervals[i][1];
                cnt++;
            }
            else{
                if(ans[j][1] < intervals[i][1])
                ans[j][1] = intervals[i][1];
                
            }
        }
        ans.resize(cnt);
        return ans;
        
    }
};