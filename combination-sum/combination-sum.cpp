class Solution {
public:
    
    vector<vector<int>>ans;
    void recurse(vector<int>&candidates, int target, int i, vector<int>&v){
        
        if(i >= candidates.size() || target < 0)
            return;
        
        if(target == 0){
            ans.push_back(v);
            return;
        }
        
        for(int j = i ; j < candidates.size() ; j++){
            v.push_back(candidates[j]);
            recurse(candidates, target - candidates[j], j, v);
            v.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<int>v;
        recurse(candidates, target, 0, v);
        
        return ans;
    }
};