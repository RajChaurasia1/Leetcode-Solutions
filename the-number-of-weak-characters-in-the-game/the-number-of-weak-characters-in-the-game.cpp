class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        
        sort(begin(properties), end(properties),[](vector<int>&a, vector<int>&b){
           if(a[0] == b[0])
               return a[1] >= b[1];
            
            return a[0] < b[0];
        });
        
        int ans = 0;
        stack<pair<int,int>>s;
        
        for(int i = 0 ; i < properties.size() ; i++){
            
            while(!s.empty() && s.top().first < properties[i][0] && s.top().second < properties[i][1]){
                ans++;
                s.pop();
            }
            
            s.push({properties[i][0],properties[i][1]});
            
        }
        
        
        return ans;
        
        
    }
};