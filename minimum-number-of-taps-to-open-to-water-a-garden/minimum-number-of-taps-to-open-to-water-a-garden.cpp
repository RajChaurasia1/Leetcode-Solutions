class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        
        
        vector<int>jump(n+1,0);
        
        for(int i = 0 ; i < ranges.size() ; i++){
            int l = max(0,i-ranges[i]);
            int r = min(n,i+ranges[i]);
            
            jump[l] = max(jump[l],r-l);
        }
        
        int jumps = 0, farthest = 0, currEnd = 0;
    for(int i=0;i<n;i++)
    {
        farthest = max(farthest, i + jump[i]);
        if(farthest >= n)
            return 1 + jumps;
        
        if(i == farthest)
            return -1;
        
        if(i == currEnd)
        {
            jumps++;
            currEnd = farthest;
        }
    }
    return jumps;
    }
};