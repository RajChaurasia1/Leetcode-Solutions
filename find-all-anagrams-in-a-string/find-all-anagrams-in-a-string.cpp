class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>ans;
        if(s.size() < p.size())
            return ans;
        int n = s.size();
       vector<int>m1(26),m2(26);
        for(int i = 0 ; i < p.size() ; i++){
            m1[p[i]-'a']++;
            m2[s[i]-'a']++;
        }
        if(m1 == m2)
            ans.push_back(0);
        for(int i = p.size() ; i < n ; i++){
         m2[s[i]-'a']++;
         m2[s[i - p.size()]-'a']--;
         // for(int i = 0 ; i < 26 ; i++){
         //     cout << m1[i] << " " << m2[i] << endl;
         // }
            if(m2 == m1){
                ans.push_back(i - p.size() + 1);
            }
                
        }
        return ans;
        
       
        
    }
};