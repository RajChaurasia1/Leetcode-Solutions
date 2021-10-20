class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
       vector<vector<int>>g(n,vector<int>(n,INT_MAX));
        
        for(auto edge : edges){
            g[edge[0]][edge[1]] = edge[2];
            g[edge[1]][edge[0]] = edge[2];
        }
        
        
        for(int k = 0 ; k < n ; k++){
            for(int i = 0 ; i < n ; i++){
                for(int j = 0 ; j < n ; j++){
                    if(g[i][k] == INT_MAX || g[k][j] == INT_MAX)
                        continue;
                    else if(g[i][k] + g[k][j] < g[i][j])
                        g[i][j] = g[i][k] + g[k][j];
                }
            }
        }
        
        int id, ans = INT_MAX;
        
        for(int i = 0 ; i < n ; i++){
            int count = 0;
                for(int j = 0 ; j < n ; j++){
                    if(i != j && g[i][j] <= distanceThreshold)
                        count++;
                }
            if(ans > count){
                id = i;
                ans = count;
            }
            else if(ans == count)
                id = max(id,i);
                
        }
        return id;
    }
};