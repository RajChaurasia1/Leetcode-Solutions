class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        
        int n = aliceValues.size(), alice = 0, bob = 0;
        vector<pair<int,int>>v;
        for(int i = 0 ; i < n ; i++){
            v.push_back({aliceValues[i] + bobValues[i], i});
        }
        
        sort(begin(v),end(v),[](pair<int,int>&a, pair<int,int>&b){
           return a.first > b.first;
            
        });
        
        for(int i = 0 ; i < n ; i++){
            if(i&1){
                bob+=bobValues[v[i].second];
            }
            else{
                alice+=aliceValues[v[i].second];
            }
        }
        
        if(alice == bob)
            return 0;
        return alice > bob ? 1 : -1;
    }
};