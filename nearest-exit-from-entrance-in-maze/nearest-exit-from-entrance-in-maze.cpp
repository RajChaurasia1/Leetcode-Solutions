class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        
        int m = maze.size(), n = maze[0].size(), lvl = 0;
        
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        
        queue<pair<int,int>>q;
        
        q.push({entrance[0],entrance[1]});
        
        vector<vector<bool>>vis(m,vector<bool>(n,false));
            
        while(!q.empty()){
            int sz = q.size();
            
            while(sz--){
            auto p = q.front();
            q.pop();
        
            int u = p.first;
            int v = p.second;
            
            if(u == entrance[0] && v == entrance[1]){
            
            }
            else{
                if(u == m - 1 || v == n - 1 || u == 0 || v == 0)
                    return lvl;
            }
                if(vis[u][v] || maze[u][v] == '+')
                    continue;
                vis[u][v] = true;
                
                
                for(int i = 0 ; i < 4 ; i++){
                    int x = u + dx[i], y = v + dy[i];
                    
                    if(x < 0 || y < 0 || x >= m || y >= n || vis[x][y] == true || maze[x][y] == '+')
                        continue;
                    
                    q.push({x,y});
                }
            }
            lvl++;
        }
        
        return -1;
        
    }
};