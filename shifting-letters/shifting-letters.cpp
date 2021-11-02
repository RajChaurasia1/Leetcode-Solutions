class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
   long long int n = shifts.size(), shift = 0;
     for(int i = n - 1 ; i >= 0 ; i--){
         shift+=shifts[i];
         
         long long k = shift % 26;
         long long int ss = s[i] + k;
         cout << ss << endl;
         if(ss > 122)
             s[i] = (char)('a' + ss - 123);
         else
            s[i] = (char)('a' + ss - 97);
     }
        return s;
    }
};