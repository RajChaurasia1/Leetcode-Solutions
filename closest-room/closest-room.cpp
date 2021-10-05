class Solution {
public:
    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
             for (int i = 0; i < queries.size(); ++i) 
                 queries[i].push_back(i); 
        
        sort(rooms.begin(), rooms.end(), [](vector<int>&a, vector<int>&b){
            return a[1] > b[1];
        }); 
        sort(queries.begin(), queries.end(), [](vector<int>&a, vector<int>&b){
            return a[1] > b[1];
        }); 
        
        set<int> st;
        vector<int> ans(queries.size(), -1); 
        
        for (int i = 0, k = 0; i < queries.size(); ++i) {
            while (k < rooms.size() && rooms[k][1] >= queries[i][1]) 
                st.insert(rooms[k++][0]); 
            if (!st.empty()) {
                auto it = st.lower_bound(queries[i][0]); 
                int diff = INT_MAX; 
                if (it != st.end()) 
                    diff = *it - queries[i][0]; 
                if (it != st.begin()){
                    auto itr = it;
                    --itr;
                    if(queries[i][0] - *itr<= diff)
                    --it;
                    }
                ans[queries[i][2]] = *it; 
            } 
        }
        return ans; 
    }
    
};