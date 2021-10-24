class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int sz = words.size(), wl = words[0].size();
        
        vector<int>ans;
        
        if(wl*sz > s.size())
            return ans;
        
        map<string,int>mp;
        
        for(auto word : words)
            mp[word]++;
        
        for(int i = 0 ; i <= s.size() - (wl*sz) ; i++){
            map<string,int>curr_mp;
            
            for(int j = i ; j < i + wl*sz ; j+=wl){
                string temp = s.substr(j,wl);
                
                if(mp.find(temp) == mp.end())
                    break;
                
                curr_mp[temp]++;
                
                if(mp[temp] < curr_mp[temp])
                    break;
            }
            
            if(mp == curr_mp)
                ans.push_back(i);
        }
        
        return ans;
        
    }
};