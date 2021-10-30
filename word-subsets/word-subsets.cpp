class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        
    vector<int>freq(26,0);
        
    for(auto s : words2){
        vector<int>temp(26,0);
        
        for(auto c : s){
            temp[c - 'a']++;
        }
        
        for(int i = 0 ; i < 26 ; i++)
            freq[i] = max(freq[i],temp[i]);
    }
        
        vector<string>ans;
        
        for(auto s : words1){
            vector<int>temp(26,0);
            for(auto c : s)
                temp[c - 'a']++;
            
            int f = 1;
            
            for(int i = 0 ; i < 26 ; i++){
                if(temp[i] < freq[i]){
                    f = 0;
                    break;
                }
            }
            
            if(f)
                ans.push_back(s);
        }
        
        return ans;
        
        
        
        
    }
};