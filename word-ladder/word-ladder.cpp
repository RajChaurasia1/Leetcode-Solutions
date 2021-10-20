class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st(wordList.begin(),wordList.end());
        if(st.find(endWord) == st.end())
            return 0;
            
        queue<string>q;
        q.push(beginWord);
        int level = 1;
        while(!q.empty()){
            
            
            int n = q.size();
            while(n--){
                string node = q.front();
                q.pop();
                for(int i = 0 ; i < node.size() ; i++){
                   // string curr = node;
                    for(char c = 'a' ; c <= 'z' ; c++){
                        char x = node[i];
                        node[i] = c;
                        // if(curr.compare(node) == 0)
                        //     continue;
                         if(node.compare(endWord) == 0)
                             return level + 1;
                        if(st.find(node)!=st.end()){
                           st.erase(node);
                            q.push(node);
                        }
                        node[i] = x;
                        
                    }
                }
            }
            level++;
            
        }
        
        return 0;
    }
};