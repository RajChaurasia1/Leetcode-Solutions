class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        
        unordered_set<string>st(bank.begin(),bank.end());
        if(st.find(end) == st.end())
            return -1;
        vector<char>mutation = {'A','C','G','T'};
        int mut = 0;
        
        queue<string>q;
        q.push(start);
        
        while(!q.empty()){
            
            int sz = q.size();
            
            while(sz--){
                string gene = q.front();
                q.pop();
                
                for(int i = 0 ; i < gene.size() ; i++){
                    
                    for(int j = 0 ; j < 4 ; j++){
                        
                        char x = gene[i];
                        gene[i] = mutation[j];
                        
                        if(gene.compare(end) == 0)
                            return mut + 1;
                        if(st.find(gene) != st.end()){
                            st.erase(gene);
                            q.push(gene);
                        }
                        gene[i] = x;
                        
                    }
                    
                }
                
            }
            ++mut;
      
        }
     
        return -1;
    }
};