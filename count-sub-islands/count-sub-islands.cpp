class Solution {
public:
    set<pair<int,int>>s;
    vector<pair<int,int>>v;
    int m, n;
    void dfs1(int i, int j, vector<vector<int>>&grid1, vector<vector<bool>>&vis){
        if(i < 0 || j < 0 || i >= m || j >= n  || !grid1[i][j] || vis[i][j])
            return ;
        
        vis[i][j] = true;
        s.insert({i,j});
        dfs1(i + 1, j, grid1, vis);
        dfs1(i, j + 1, grid1, vis);
        dfs1(i - 1, j, grid1, vis);
        dfs1(i, j - 1, grid1, vis);
        
    }
    
     void dfs2(int i, int j, vector<vector<int>>&grid2, vector<vector<bool>>&vis){
        if(i < 0 || j < 0 || i >= m || j >= n  || !grid2[i][j] || vis[i][j])
            return ;
        
        vis[i][j] = true;
        v.push_back({i,j});
        dfs2(i + 1, j, grid2, vis);
        dfs2(i, j + 1, grid2, vis);
        dfs2(i - 1, j, grid2, vis);
        dfs2(i, j - 1, grid2, vis);
        
    }
    
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        
         m = grid1.size(), n = grid1[0].size();
        
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(!vis[i][j])
                    dfs1(i,j,grid1,vis);
            }
        }
        
        vis = vector<vector<bool>>(m,vector<bool>(n,false));
        
        int ans = 0;
        
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                v.clear();
                int f = 1;
                if(!vis[i][j])
                    dfs2(i,j,grid2,vis);
               
                if(v.size() > 0){
                for(int k = 0 ; k < v.size() ; k++){
                    if(s.find({v[k].first, v[k].second}) == s.end()){
                        f = 0;
                        break;
                    }
                }
                
                if(f)
                    ans++;
                }
                
            }
        }
        
        return ans;
        
    }
};