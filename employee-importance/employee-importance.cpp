/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
  
    unordered_map<int,Employee*>mp;
    int dfs(int id){
        int ans = mp[id]->importance;
        
        for(auto x : mp[id]->subordinates){
            ans += dfs(x);
        }
        
        return ans;
    }
    int getImportance(vector<Employee*> employees, int id) {
        for(auto i : employees)
            mp[i->id] = i;
        
        return dfs(id);
    }
};