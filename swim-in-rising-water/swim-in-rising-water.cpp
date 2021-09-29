class Solution {
public:
    
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    
    int swimInWater(vector<vector<int>>& grid) {
        
        int n = grid.size();
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        vector<vector<bool>>vis(n,vector<bool>(n,false));
        
        pq.push({grid[0][0],0,0});
        
        vis[0][0] = true;
        
        while(!pq.empty()){
            int x = pq.top()[1];
            int y = pq.top()[2];
            int wt = pq.top()[0];
            pq.pop();
            if(x == n - 1 && y == n - 1)
                return wt;
            
          
            
            for(int i = 0 ; i < 4 ; i++){
                int nx = x + dx[i], ny = y + dy[i];
                
                if(nx < 0 || ny < 0 || nx >= n || ny >= n || vis[nx][ny] == true)
                    continue;
                vis[nx][ny] = true;
                pq.push({max(wt,grid[nx][ny]),nx,ny});
            }
            
            
        }
        
        return -1;
    }
};