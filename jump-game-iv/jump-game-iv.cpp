class Solution {
public:
    int n, vis[50001];
    
    int minJumps(vector<int>& arr) {
       // memset(dp,-1,sizeof(dp));
        memset(vis,0,sizeof(vis));
        n = arr.size();
        queue<int>q;
        q.push(0);
        unordered_map<int,vector<int>>mp;
        int level = 0;
        for(int i = 0 ; i < n ; i++)
            mp[arr[i]].push_back(i);
        while(!q.empty()){
            int sz = q.size();
            
            while(sz--){
                int i = q.front();
             //   cout << i << endl;
                q.pop();
                if(i == n - 1)
                    return level;
                if(i < 0 || i >= n)
                    continue;
               
               if(i - 1 >= 0 && mp.find(arr[i- 1]) != mp.end())
                q.push(i - 1);
              if(i + 1 < n && mp.find(arr[i + 1]) != mp.end()){
                if(i + 1 == n - 1)
                    return level + 1;
                q.push(i + 1);
              }

    
                if(mp.find(arr[i])!=mp.end()){
                for(auto x : mp[arr[i]]){
                    if(x != i){
                        q.push(x);
                        if(x == n - 1)
                            return level + 1;
                    }
                }
                    mp.erase(arr[i]);
                }
                
            }
            level++;
        }
        return -1;
    }
};