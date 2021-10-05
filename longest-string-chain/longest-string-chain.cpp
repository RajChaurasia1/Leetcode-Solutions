class Solution {
public:
    int longestStrChain(vector<string>& words) {
     
        sort(begin(words),end(words),[&](string &a, string &b){
            if(a.size() == b.size())
                return  a < b;
            
            return a.size() < b.size();
        });
        
        int ans = 0;
        
        unordered_map<string,int>mp;
        
        for(int i = 0 ; i < words.size() ; i++){
            string succ = words[i];
            
            int curr = 1;
            
            for(int j = 0 ; j < words[i].size() ; j++){
                
                string pred = succ.substr(0,j) + succ.substr(j + 1);
                
                if(mp.find(pred) != mp.end()){
                    int prev = mp[pred];
                    
                    curr = max(curr, prev + 1);
                }
                
                mp[succ] = curr;
                ans = max(ans, curr);
            }
            
        }
        return ans;
        
    }
};