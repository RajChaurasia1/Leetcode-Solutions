class Solution {
public:

    int m, n;
    vector<vector<int>>ans;
   
    void dfs(int i, int j, vector<vector<int>>& heights, vector<vector<bool>>& ocean, int depth){
        if(i < 0 || j < 0 || i >= m || j >= n || heights[i][j] < depth || ocean[i][j] == true)
            return;
        
        ocean[i][j] = true;
        dfs(i + 1, j, heights, ocean, heights[i][j]);
        dfs(i - 1, j, heights, ocean, heights[i][j]);
        dfs(i, j + 1, heights, ocean, heights[i][j]);
        dfs(i, j - 1, heights, ocean, heights[i][j]);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        m = heights.size(), n = heights[0].size();
        vector<vector<bool>>pacific(m,vector<bool>(n,false));
        vector<vector<bool>>atlantic(m,vector<bool>(n,false));

        for(int i = 0 ; i < m ; i++){
            dfs(i, 0, heights, pacific, INT_MIN);
            dfs(i,n - 1, heights, atlantic, INT_MIN);
        }
        
        for(int i = 0 ; i < n ; i++){
            dfs(0, i, heights, pacific, INT_MIN);
            dfs(m - 1, i, heights, atlantic, INT_MIN);
        }
        
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(atlantic[i][j] && pacific[i][j])
                    ans.push_back({i,j});
            }
        }
        return ans;
    }
};