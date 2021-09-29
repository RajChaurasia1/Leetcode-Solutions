class Solution {
public:
    
    int dx[4] = {1,0,0,-1};
    int dy[4] = {0,1,-1,0};
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int n = heights.size(), m = heights[0].size();
    
        vector<vector<int>> dist(n, vector<int>(m,INT_MAX)); 
        priority_queue<vector<int>, vector<vector<int> >, greater<vector<int> > > pq;
     
        pq.push({0,0,0});
        
        vector<int> v;
    
        while(!pq.empty()){
            int x = pq.top()[1];
            int y = pq.top()[2];
            int wt = pq.top()[0];
         
            pq.pop();
            
            if(wt > dist[x][y]) continue;
            
            if(x == n-1 && y == m-1) 
                return wt;
            
            for(int i = 0; i < 4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx < 0 || ny < 0 || nx >= n || ny >= m) 
                    continue;
                int newDist = max(wt,abs(heights[x][y] - heights[nx][ny]));
                
                if(dist[nx][ny] > newDist){
                    dist[nx][ny] = newDist;
                    pq.push({dist[nx][ny],nx,ny});
                }
            }          
        }
        return 0;
    }
};