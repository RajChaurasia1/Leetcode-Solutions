class Solution {
public:
    int minPairSum(vector<int>& nums) {
        
        priority_queue<int>pq;
        //priority_queue<int,vector<int>,greater<int>>mn;
        multiset<int>s;
        multiset<int,greater<int>>st;
        for(int i = 0 ; i < nums.size() ; i++){
            s.insert(nums[i]);
            st.insert(nums[i]);
        }
        
        
        while(!s.empty()){
            
            int mx = *st.begin(), mn = *s.begin();
           // cout << mx << " " << mn << endl;
            st.erase(st.find(mx)), st.erase(st.find(mn));
            s.erase(s.find(mx)), s.erase(s.find(mn));
            pq.push(mx + mn);
        }
        return pq.top();
    }
};