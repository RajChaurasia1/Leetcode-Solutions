class Solution {
public:
    
    vector<vector<string>>ans;
    bool ispalindrome(int x, int y, string s){
        
        while(x <= y){
            if(s[x] == s[y]){
                ++x;
                --y;
            }
            else
                return false;
        }
        
        return true;
        
        
    }
    void pp(int i,string s, vector<string>&v){
        if(i >= s.size()){
            ans.push_back(v);
            return;
        }
        
        for(int j = i ; j < s.size() ; j++){
            if(ispalindrome(i,j,s)){
                v.push_back(s.substr(i,j - i + 1));
                pp(j + 1,s,v);
                v.pop_back();
            }
        }
        
        return;
        
    }
    
    vector<vector<string>> partition(string s) {
        vector<string>v;
        pp(0,s,v);
        return ans;
    }
};