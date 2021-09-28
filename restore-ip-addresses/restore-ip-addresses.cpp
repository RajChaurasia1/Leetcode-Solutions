class Solution {
public:
    vector<string>ans;
    bool isvalid(string s){
        if(s[0] == '0')
            return false;
        int num = stoi(s);
        if(num <= 255)
            return true;
        return false;
    }
    void ip(string &s, int i, int part, string res){
        //cout << i << " part " << part << " " << res << endl;
        if(i == s.size() || part == 4){
            if(i == s.size() && part == 4){
                res.pop_back();
                ans.push_back(res);
                
            }
            return;
        }
        
        ip(s,i + 1,part + 1, res + to_string(s[i] - '0') + ".");
        if(i + 2 <= s.size() && isvalid(s.substr(i,2)))
            ip(s,i + 2,part + 1,res + s.substr(i,2) + ".");
        if(i + 3 <= s.size() && isvalid(s.substr(i,3)))
            ip(s,i + 3,part + 1,res + s.substr(i,3) + ".");
    }
    vector<string> restoreIpAddresses(string s) {
         ip(s,0,0,"");
        return ans;
    }
};