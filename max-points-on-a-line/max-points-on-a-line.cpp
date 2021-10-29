class Solution {
public:
    
  double slope(vector<int>&a,vector<int>&b){
            
            int dx = (a[0]-b[0]);
            int dy = (a[1]-b[1]);
            
			
            if(dx==0)
                return (double)INT_MAX;
            
            return (double)dy/dx;
        }
        
    
    
    int maxPoints(vector<vector<int>>& points) {
         int n = points.size();
        
        if(n < 3)
           return n;
        
	
        int ans = 0;
        
		
        for(int i = 0; i < n; i++){
            unordered_map<double,int>slopes;
            for(int j = 0 ; j < n; j++){
			
                if(i!=j){
				
                    auto m = slope(points[i],points[j]);
                    slopes[m]++;
                }
            }

			
            for(auto &[x,y]: slopes)
                ans = max(ans,y);
        }

		
        return ans + 1;
    }
};