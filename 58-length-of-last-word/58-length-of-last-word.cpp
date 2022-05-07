class Solution {
public:
    int lengthOfLastWord(string s) {
        string last_word = "";
        int last_size = 0, last = 0;
        
        for(int i = 0 ; i < s.size() ; i++){
            
            if(s[i] == ' '){
                if(last != 0)
                last_size = last;
                last = 0;
                last_word = "";
                continue;
            }
            last_word += s[i];
            last = last_word.size();
            if(last != 0)
            last_size = last;
            
        }
        
        
        return last_size;
        
    }
};