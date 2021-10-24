class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        
        vector<int>adj[n + 1];
        vector<int>indegree(n + 1, 0);
        
        for(auto relation : relations){
            adj[relation[0]].push_back(relation[1]);
      
            indegree[relation[1]]++;
        }
        
        
        queue<int>q;
        int t = 0, cnt = 0;
        vector<int>ans(n + 1,0);
        for(int i = 1 ; i <= n ; i++)
            if(indegree[i] == 0){
                ans[i] = time[i - 1];
                q.push(i);
            }
        
        
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int u = q.front();
                q.pop();
                for(auto v : adj[u]){
                    ans[v] = max(ans[v],ans[u] + time[v - 1]);
                    --indegree[v];
                    if(indegree[v] == 0){
                        q.push(v);
                    }
                }
                
                
            }
        }
        return *max_element(ans.begin(),ans.end());
    }
};