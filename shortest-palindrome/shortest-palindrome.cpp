class Solution {
public:
    
    void kmp(string s, vector<int>&lps){
        lps[0] = 0;
        int i = 1, len = 0;
        
        while(i < s.size()){
            
            if(s[i] == s[len]){
                len++;
                lps[i] = len;
                i++;
            }
            else{
                if(len != 0)
                    len = lps[len - 1];
                else{
                    lps[i] = 0;
                    ++i;
                }
            }
            
            
            
        }
    }
    
    
    string shortestPalindrome(string s) {
        string temp = s;
        string rev = temp;
        reverse(begin(rev),end(rev));
        rev = "#" + rev;
        temp += rev;
        
        vector<int>lps(temp.size());
        kmp(temp,lps);
        int add = lps[lps.size() - 1];
        add = s.size() - add;
        string ans;
        for(int j = s.size() - 1 ; j >= 0 && add > 0; j--){
            ans += s[j];
            --add;
        }
        
        ans += s;
        
        return ans;
    }
};