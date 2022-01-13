class Solution {
public:
    static bool comp(vector<int>&a,vector<int>&b){
        if(a[1] == b[1])
            return a[0] <= b[0];
        return a[1] < b[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size(), ans = 1;
        sort(points.begin(),points.end(),comp);
        int f = points[0][0], s = points[0][1];
        
        for(int i = 1 ; i < n ; i++){
            if(s >= points[i][0]){
                f = points[i][0];
                if(s > points[i][1])
                    s = points[i][1];
            }
            else{
                ++ans;
                f = points[i][0];
                s = points[i][1];
            }
        }
        return ans;
    }
};