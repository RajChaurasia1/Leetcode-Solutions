class Solution {
public:
    int dx[8] = {0,0,1,-1,-1,1,1,-1};
    int dy[8] = {1,-1,0,0,1,1,-1,-1};
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid){
                int n = grid.size();
                queue<pair<int,int>>q;
                q.push({0,0});
                vector<vector<bool>>vis(n,vector<bool>(n,false));
               
                int level = 1;
               while(!q.empty()){
                   int sz = q.size();
                   
                   while(sz--){
                       auto p = q.front();
                       q.pop();
                       
                       int u = p.first;
                       int v = p.second;
                      // cout << u << " " << v << endl;
                       if(u == n - 1 && v == n - 1)
                           return level;
                       
                       if(vis[u][v] == true || grid[u][v] == 1)
                           continue;
                        vis[u][v] = true;
                       for(int i = 0 ; i < 8 ; i++){
                           int nx = u + dx[i], ny = v + dy[i];
                           if(nx < 0 || ny < 0 || nx >= n || ny >= n || grid[nx][ny] == 1 || vis[nx][ny] == true)
                               continue;
                           q.push({nx,ny});
                          
                       }
                       
                   }
                   level++;
               }                 
                                
                                
               return -1; 
             }
                                        
};