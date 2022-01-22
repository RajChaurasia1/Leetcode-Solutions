class Solution {
public:
    
    int find(int u, vector<int>&parent){
        if(u == parent[u])
            return u;
        return parent[u] = find(parent[u],parent);
    }
    
    void union_(int u, int v, vector<int>&parent, vector<int>&rank){
        u = find(u,parent);
        v = find(v,parent);
        
        if(u == v)
            return;
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
        return;
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int>parent(n),rank(n,0);
        for(int i = 0 ; i < n ;  i++)
            parent[i] = i;
        for(int i = 0 ; i < isConnected.size() ; i++){
            for(int j = 0 ; j < isConnected.size() ; j++){
                if(i != j && isConnected[i][j]){
                    if(find(i,parent) != find(j,parent)){
                        union_(i,j,parent,rank);
                    }
                }
            }
        }
        
        
        set<int>s;
        
        for(int i = 0 ; i < n ; i++){
            s.insert(find(i,parent));
        }
        
        return s.size();
    }
};