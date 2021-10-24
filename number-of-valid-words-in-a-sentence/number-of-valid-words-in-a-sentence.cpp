class Solution {
public:
    int countValidWords(string sentence) {
        
        stringstream ss(sentence);
        string words;
        int ans = 0;
        while(ss >> words){
            int f = 1, hyp = 0, excl = 0;
            if(words.size() == 1){
                if(words[words.size() - 1] == ',' || words[words.size() - 1] == '.' || words[words.size() - 1] == '!')
                    f = 1;
                else if(words[words.size() - 1] == '-' )
                    f = 0;
                else if(words[0] >= 'a' && words[0] <= 'z')
                    f = 1;
                else 
                    f = 0;
            }
            else{
            if((words[words.size() - 1] == ',' || words[words.size() - 1] == '.') && words[words.size() - 2] != '!')
                words.pop_back();
            
            for(int i = 0 ; i < words.size() ; i++){
               if(words[i] - '0' >= 0 && words[i] - '0' <= 9)
                   f = 0;
               else if(words[i] == '!')
                    excl++;
               else if(words[i] == '-')
                   hyp++;
                else if(words[i] >= 'a' && words[i] <= 'z')
                    continue;
                else
                    f = 0;
            }
            if(hyp > 1 || excl > 1)
                f = 0;
            
            if(f){
                if(words[words.size() - 1] == '!'){
                    --excl;
                words.pop_back();}
                if(excl > 0)
                    f = 0;
                if(words[0] == '-')
                    f = 0;
        
                if(words[words.size() - 1] == '-')
                    f = 0;
            }
            }
            if(f){
                cout << words << endl;
                ++ans;}
        }
        
        return ans;
        
    }
};