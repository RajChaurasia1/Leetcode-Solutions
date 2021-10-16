class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        int n = values.size(), sum = 0;
        vector<vector<int>>v(n,vector<int>(2));
        
        unordered_map<int,int>mp,cnt;
        int i = 0;
        for(auto label : labels){
            
            mp[label]++;
            cnt[label] = 0;
            v[i][0] = values[i];
            v[i][1] = label;
            ++i;
        }
        
        int sz = 0;
        i = 0;
        
        sort(begin(v),end(v),[](vector<int>&a,vector<int>&b){
           
            return a[0] > b[0];
            
        });
       
        
        for(int i = 0 ; i < n ; i++)
            cout << v[i][0] << " ";
        
        
        while(i < n && sz < numWanted){
            
            if(mp[v[i][1]] > 0 && cnt[v[i][1]] < useLimit){
                //cout << v[i][1] << " ";
                sum += v[i][0];
                --mp[v[i][1]];
                ++cnt[v[i][1]];
                
                ++sz;
            }
            ++i;
            
        }
       
        return sum;
    }
};