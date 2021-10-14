class Solution {
public:
    
    
     vector<vector<int>>ans;
    void recurse(int n, vector<int>&nums, vector<int>&v){
   
        if(v.size() == n){
            ans.push_back(v);
            return;
        }
            
        for(int j = 0 ; j < n ; j++){
            if(find(v.begin(),v.end(),nums[j]) == v.end()){
            v.push_back(nums[j]);
            recurse(n, nums, v);
            v.pop_back();}
        }
            
    }
    
 
    vector<vector<int>> permute(vector<int>& nums) {
        
            vector<int>v;
            int n = nums.size();
            recurse(n, nums, v);
    
        return ans;
        
    }
};