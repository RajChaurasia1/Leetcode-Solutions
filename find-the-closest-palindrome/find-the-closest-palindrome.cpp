class Solution {
public:
    string nearestPalindromic(string n) {
        if(n.size() == 1)
            return to_string(stoi(n) - 1);
        
        
        int d = n.size();
        vector<long long int>pal;
        pal.push_back(pow(10,d - 1) - 1); // digit - 1 digits
        pal.push_back(pow(10,d) +  1); // digit + 1 digits
        
        
        
        int mid = (1 + d)/2;
        long long int prefix = stol(n.substr(0,mid)); 
        vector<long long int>same = {prefix - 1, prefix, prefix + 1}; 
        
        for(auto x : same){
            string suff = to_string(x);
            if(d & 1)
                suff.pop_back();
            
            reverse(begin(suff),end(suff));
            string num = to_string(x) + suff;
            pal.push_back(stol(num));
        }
        
        
        long long int diff = INT_MAX, num = stol(n), ans = INT_MAX;
        
        for(int i = 0 ; i < pal.size() ; i++){
            
            if(num != pal[i] && diff > abs(pal[i] - num)){
                diff = abs(pal[i] - num);
                ans = pal[i];
            }
            else if(diff == abs(pal[i] - num)){
                ans = min(ans,pal[i]);
            }
        }
        
        return to_string(ans);
        
    }
};