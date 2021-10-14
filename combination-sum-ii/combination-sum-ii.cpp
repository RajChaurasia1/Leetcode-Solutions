class Solution {
public:
    
        vector<vector<int>>ans;
 
    void recurse(vector<int>&candidates, int target, int i, vector<int>&v){

        
        if(target == 0){
       
                ans.push_back(v);
       
            return;
        }
        
        for(int j = i ; j < candidates.size() ; j++){
            
            if(i < j && candidates[j] == candidates[j - 1])               //to avoid picking up the same combnations i.e. we don't pick same element for certain kth position of a combination 
                continue;
            if(candidates[j] > target)
                break;
            
            v.push_back(candidates[j]);
            recurse(candidates, target - candidates[j], j + 1, v);
            v.pop_back();
        }
        
    }
   
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
            vector<int>v;
        recurse(candidates, target, 0, v);
        
        return ans;
    }
};