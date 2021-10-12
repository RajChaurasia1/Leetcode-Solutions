class Solution {
public:
    bool checkValidString(string s) {
        
        stack<int>b,st;
        
        
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i] == '(')
                b.push(i);
            else if(s[i] == '*')
                st.push(i);
            else{
                if(b.empty() && st.empty())
                    return false;
                if(!b.empty())
                    b.pop();
                else if(!st.empty())
                    st.pop();
            }
        }
        
        
        while(!b.empty()){
            
          if(!st.empty() && b.top() < st.top()){
              st.pop();
              b.pop();
          }
          else
            return false;      
            
        }
        
        return b.empty();
            
        
    }
};