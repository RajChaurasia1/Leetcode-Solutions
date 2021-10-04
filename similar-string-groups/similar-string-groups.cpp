class Solution {
public:
    
    vector<int>par,rank;
    int find(int u){
        if(u == par[u]){
            return u;
        }
        return par[u] = find(par[u]);
    }
    
    void union_(int u, int v){
        u = find(u);
        v = find(v);
        
        
        if(rank[u] > rank[v]){
            par[v] = u;
        }
        else if(rank[v] > rank[u]){
            par[u] = v;
        }
        else{
            par[v] = u;
            rank[u]++;
        }
    }
    
    
    bool similar(string a, string b){
        int diff = 0;
        for(int i = 0 ; i < a.size() ; i++){
            if(a[i] != b[i]){
                diff++;
            }
        }
        
        return (diff <= 2) ? true : false;
    }
    
    int numSimilarGroups(vector<string>& strs) {
        
       par =  vector<int>(strs.size());
       rank = vector<int>(strs.size(),0);
        
        for(int i = 0 ; i < strs.size() ; i++)
            par[i] = i;
        for(int i = 0 ; i < strs.size() ; i++){
            int par1 = find(i);
            for(int j = i + 1 ; j < strs.size() ; j++){
                int par2 = find(j);
                if(similar(strs[i],strs[j])){
                if(par1 != par2){
                    union_(i,j);
                    }
                }
            }
        }
        
        int ans = 0;
        
        for(int i = 0 ; i < strs.size() ; i++)
            if(par[i] == i)
                ans++;
        
        return ans;
    }
};