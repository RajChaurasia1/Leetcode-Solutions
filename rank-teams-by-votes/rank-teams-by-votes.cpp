class Solution {
public:
    string rankTeams(vector<string>& votes) {
        
        int n = votes.size();
        int m = votes[0].size();
        
        vector<vector<int>>rank(26, vector<int>(m + 1, 0));
        
        
        for(int i = 0 ; i < 26 ; i++)
            rank[i][m] = i;
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                rank[votes[i][j] - 'A'][j]++;
                }
        }
        
        string ans;
        sort(begin(rank),end(rank),[&](vector<int>&a, vector<int>&b){
           for(int i = 0 ; i < m ; i++){
               if(a[i] != b[i])
                    return a[i] > b[i];
               // if(a[i] > b[i])
               //      return true;
               // else if(b[i] > a[i])
               //      return false;
            }
            return a[m] < b[m];
        });
        
        for(int i = 0 ; i < m ; i++){
            //cout << rank[i][m]<<endl;
            ans += rank[i][m] + 'A';}
        
        return ans;
    }
};