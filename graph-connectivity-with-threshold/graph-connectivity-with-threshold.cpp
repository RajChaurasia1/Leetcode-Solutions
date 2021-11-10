class Solution {
public:
    
    int find_par(int u, vector<int>&parent){
        if(u == parent[u])
            return u;
        return parent[u] = find_par(parent[u],parent);
    }
    
    void union_(int u, int v, vector<int>&parent){
        u = find_par(u,parent);
        v = find_par(v,parent);
        
        
        if(u == v)
            return;
        
        parent[v] = u;
        
        return;
    }
    
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        
        vector<int>parent(n + 1);
        
        for(int i = 0 ; i < n + 1 ; i++)
            parent[i] = i;
        
        for(int i = threshold + 1 ; i <= n ; i++){
            for(int j = 2 ; j*i <= n ; j++){
                union_(i,i*j,parent);
            }
        }
        
        vector<bool>ans(queries.size(),false);
        int i = 0;
        for(auto v : queries){
            if(find_par(v[0],parent) == find_par(v[1],parent))
                ans[i] = true;
            
            ++i;
        }
        
        return ans;
    }
};