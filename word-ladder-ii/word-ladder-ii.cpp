class Solution {
public:
    vector<vector<string>>ans;
    void dfs(string &beginWord, string &endWord, unordered_map<string,unordered_set<string>>&adj, vector<string>temp){
        temp.push_back(beginWord);
        if(beginWord == endWord){
            ans.push_back(temp);
            return ;
        }
        
        for(auto v : adj[beginWord]){
            dfs(v,endWord,adj,temp);
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
   
        unordered_map<string,unordered_set<string>>adj;
        unordered_map<string,int>vis;
        unordered_set<string>s(wordList.begin(),wordList.end());
        queue<string>q;
        if(s.find(endWord) == s.end())
            return {};
        q.push(beginWord);
        vis[beginWord] = 0;
        int min_size = INT_MAX;
        while(!q.empty()){
            int sz = q.size() ;
            
            while(sz--){
                string word = q.front();
               
                q.pop();
                string parent = word;
                for(int i = 0 ; i < word.size() ; i++){
                    char temp = word[i];
                    for(char c = 'a' ; c <= 'z' ; c++){
                        if(c == temp)
                            continue;
                       
                        word[i] = c;
                     
                        
                        if(s.count(word)){
                            if(!vis.count(word)){
                                vis[word] = vis[parent] + 1;
                                q.push(word);
                                adj[parent].insert(word);
                            }
                            else if(vis[word] == vis[parent] + 1){
                                adj[parent].insert(word);
                            }
                        }
                        
                        
//                         if(endWord.compare(word) == 0 && path.back() != endWord){
//                             vector<string>temp_path = path;
//                             temp_path.push_back(word);
//                             ans.push_back(temp_path);
//                             min_size = min(min_size,(int)temp_path.size());
//                             break;
                            
//                         }
                        
//                         if(s.find(word) != s.end()){
//                             vector<string>temp_path = path;
//                             temp_path.push_back(word);
//                             q.push({word,temp_path});
//                             s.erase(word);
//                         }
                        
                        word[i] = temp;
                    }
                }
            }
        }
        
         vector<string>temp;
        dfs(beginWord,endWord,adj,temp);
        return ans;
    }
};