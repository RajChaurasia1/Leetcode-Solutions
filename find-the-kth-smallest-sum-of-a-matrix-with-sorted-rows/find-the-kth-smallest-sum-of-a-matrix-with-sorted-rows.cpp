class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        
       int m = mat.size(), n = mat[0].size(); 
        
       set<pair<int, vector<int>>>s;
       pair<int, vector<int>>p; 
        
        for(int i = 0 ; i < m ; i++){
            p.first += mat[i][0];
            p.second.push_back(0);
        }
        
        s.insert(p);
        
        if(k == 1)
            return p.first;
        
        while(k > 1){
            auto it = s.begin();
            pair<int, vector<int>> a = *it;
            s.erase(it);
            for(int i = 0 ; i < m ; i++){
                if(a.second[i] + 1 < n){
                    a.first +=  mat[i][a.second[i] + 1] - mat[i][a.second[i]];
                    a.second[i]++;
                    s.insert(a);
                    a.second[i]--;
                    a.first += mat[i][a.second[i]] - mat[i][a.second[i] + 1];    
                }
            }
            k--;
        }
        
        auto temp = s.begin();
        int ans= (*temp).first;
        return ans;
        
    }
};