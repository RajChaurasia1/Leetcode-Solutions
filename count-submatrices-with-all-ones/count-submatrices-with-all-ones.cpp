class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size(), ans = 0;
        
        for(int i = 0 ; i < m ; i++){
            for(int j = n - 2 ; j >= 0 ; j--){
                if(mat[i][j])
                mat[i][j] += mat[i][j + 1];
            }
        }
        
        
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                
                int mn = INT_MAX;
                
                for(int k = i ; k < m ; k++){
                    if(!mat[k][j])
                        break;
                    mn = min(mn, mat[k][j]);
                    ans += mn;
                }
                
                
                
            }
        }
        
        return ans;
        
    }
};