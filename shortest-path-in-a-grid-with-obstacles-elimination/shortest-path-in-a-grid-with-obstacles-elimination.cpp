class Solution {
public:
    int dx[4] = {1,0,0,-1};
    int dy[4] = {0,1,-1,0};
   
    
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size(),level = 0;
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{0,grid[0][0]}});
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        vector<vector<int>>obstacle(m,vector<int>(n,0));
        obstacle[0][0] = grid[0][0];
        while(!q.empty()){
            
            int sz = q.size();
            while(sz--){
            auto p = q.front();
            q.pop();
            
            int i = p.first;
            int j = p.second.first;
            int currobstacle = p.second.second;
         
            if(i == m - 1 && j == n -  1)
                return level;
        
            for(int r = 0 ; r < 4 ; r++){
             int nx = i + dx[r], ny = j + dy[r];
                if(nx < 0 || ny < 0 || nx >= m || ny >= n)
                    continue;
                int oldobs = obstacle[nx][ny];
                int newobs = currobstacle + grid[nx][ny];
                
                if((!vis[nx][ny]) && newobs <= k){
                    q.push({nx,{ny,newobs}});
                    obstacle[nx][ny] = newobs;
                    vis[nx][ny] = true;
                }
                
                if(oldobs > newobs && newobs <= k){
                    q.push({nx,{ny,newobs}});
                    obstacle[nx][ny] = newobs;
                    vis[nx][ny] = true;
                }
            }
        }
            level++;
        }
     
        return -1;
        
    }
};