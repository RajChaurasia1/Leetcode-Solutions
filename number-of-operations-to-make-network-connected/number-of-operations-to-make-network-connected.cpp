class Solution {
public:
    
    vector<int>parent,rank;
    
    int find(int u){
        if(u == parent[u])
            return u;
        return parent[u] = find(parent[u]);
    }
    
    bool union_(int u, int v){
        u = find(u);
        v = find(v);
        
        if(u == v)
            return true;
        else{
            if(rank[u] > rank[v]){
                parent[v] = u;
                
            }
            else if(rank[v] > rank[u]){
                parent[u] = v;
            }
            else{
                parent[v] = u;
                rank[u]++;
            }
            return false;
        }
    }
    
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        parent = vector<int>(n);
        rank = vector<int>(n,0);
        for(int i = 0 ; i < n ; i++){
            parent[i] = i;
        }
        int components = 0, redundant = 0;
        for(auto edge : connections){
            if(find(edge[0]) == find(edge[1])){
                redundant++;
            }
            else{
                union_(edge[0],edge[1]);
            }
        }
        
        for(int i = 0 ; i < n ; i++){
            if(parent[i] == i)
                components++;
        }
        
        if(redundant >= components - 1)
            return components - 1;
        return -1;
    }
};