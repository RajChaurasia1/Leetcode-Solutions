class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        string ans;
        stringstream ss(paragraph);
        string word;
        unordered_map<string,int>mp;
        int j = 0;
        
        while(j < paragraph.size()){
            if((paragraph[j] >= 'a' && paragraph[j] <= 'z') || (paragraph[j] >= 'A' && paragraph[j] <= 'Z')){
                
            int i = j;
            word = "";
            while(i < paragraph.size() && (paragraph[i] != ',' && paragraph[i] != '.' && paragraph[i] != '!' && paragraph[i] != ' ')){
                if((paragraph[i] >= 'a' && paragraph[i] <= 'z') || (paragraph[i] >= 'A' && paragraph[i] <= 'Z')){
                word += paragraph[i];
                ++i;}
                else
                    break;
            }
           
           // cout << word << endl;
           transform(begin(word),end(word),begin(word),::tolower);
            if(find(begin(banned),end(banned),word) == end(banned))
                mp[word]++;
                //cout << word << endl;
              j = i;
                ++j;
                
          }
                 else{
                     ++j;
                 }
        }
                  
        
        
        int mx = 0;
        
        for(auto x : mp){
            if(x.second > mx){
                mx = max(mx,x.second);
                ans = x.first;
            }
        }
        
        return ans;
    }
};