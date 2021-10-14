class Solution {
public:
    vector<vector<int>>ans;
    void recurse(int i, int k, int n,vector<int>&v){
        if(k < 0){
            return;
        }
        
        if(k == 0){
            ans.push_back(v);
            return;
        }
            
        for(int j = i ; j <= n ; j++){
            v.push_back(j);
            recurse(j + 1, k - 1, n, v);
            v.pop_back();
        }
            
    }
    
    
    vector<vector<int>> combine(int n, int k) {
        
       // for(int i = 1 ; i <= n ; i++){
            vector<int>v;
          //  v.push_back(1);
            recurse(1,k,n,v);
        //}
        return ans;
        
    }
};