class Solution {
public:
    string reverseWords(string s) {
        
        string ans, word;
        stack<string> st;
        
        stringstream ss(s);
        
        while(ss >> word){
            st.push(word);
        }
        
        while(!st.empty()){
            if(st.size() > 1){
                ans += st.top();
                ans += " ";
            }
            else
                ans += st.top();
            
            st.pop();
        }
        
        return ans;
        
    }
};