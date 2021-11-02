class Solution {
public:
    string replaceDigits(string s) {
        for(int i = 1 ; i < s.size() ; i+=2){
            int shift = (s[i] - '0')%26;
            int curr = s[i - 1] + shift;
           // cout << curr << endl;
            if(shift > 122)
                s[i] = (char)('a' + curr - 123);
            else
                s[i] = (char)('a' + curr - 97);
            
        }
        
        return s;
    }
};