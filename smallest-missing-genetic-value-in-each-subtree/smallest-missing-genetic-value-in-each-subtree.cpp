class Solution {
public:
    bool vis[100002] = {};
    
   void dfs(int i, vector<int>adj[], vector<int>&nums){
       if(!vis[nums[i]]){
           vis[nums[i]] = true;
           
           for(auto j : adj[i])
               dfs(j,adj,nums);
       }
       
       return;
   } 
    
    vector<int> smallestMissingValueSubtree(vector<int>& parents, vector<int>& nums) {
        int n = nums.size(), id;
        vector<int>ans(n,1);
        vector<int>adj[n];
        
        for(int i = 1 ; i < n ; i++)
            adj[parents[i]].push_back(i);
        
        for(int i = 0 ; i < n ; i++){
            if(nums[i] == 1){
                id = i;
                break;
            }
        }
        
        int mis = 1;
        
        for( ; id < n && id != -1 ; id = parents[id]){
            dfs(id,adj,nums);
            
            while(vis[mis])
                ++mis;
            
            ans[id] = mis;
        }
        return ans;
    }
};