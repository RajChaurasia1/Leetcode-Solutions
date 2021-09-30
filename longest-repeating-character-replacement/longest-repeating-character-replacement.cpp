class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int n = s.size();
        
         int e = 0, st = 0, chg = k, ans = INT_MIN, mx = INT_MIN;
        
        for(int i = 0 ; i < 26 ; i++){
            
            string ss(n,'A' + i);
            
             e = 0, st = 0, chg = k, ans = INT_MIN;
           // cout<<ss<<endl;
            while(e < n){
             //   cout << st << " " <<  e << " chg " << chg << endl;
                if(chg > 0 && s[e] != ss[e]){
                    chg--;
                    ans = max(ans,e-st+1);
                   // cout<<"ans"<<ans<<endl;
                    ++e;
                }
                else{
                    if(chg == 0 && s[e] != ss[e]){
                        while(s[st] == ss[st]){
                            ++st;
                        }
                        if(s[st] != ss[st]){
                        chg++;
                        if(st + 1 < n)
                            st++;
                        }
                        
                    }
                    else if(s[e] == ss[e]){
                        ans = max(ans,e-st+1);
                        e++;}
                    
                    
                }
                
                // cout <<  " chg " << chg << endl;
                // cout << " st " << st << " e " << e << endl;
            }
            mx = max(ans,mx);
        }
        
        return mx;
    }
};