class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        
        int n = arr.size();
        vector<int>b(begin(arr),end(arr)),ans;
        int e = 0;
        
        sort(begin(b),end(b));
        
        while(e < n && arr != b){
            int id = max_element(begin(arr),begin(arr) + n - e) - begin(arr);
            ans.push_back(id + 1);
            for(int i = 0 ; i <= id ; i++,id--){
                swap(arr[i], arr[id]);
            }
            
            id = n - e - 1;
            ans.push_back(id + 1);
            
            for(int i = 0 ; i <= id ; i++,id--){
                swap(arr[i],arr[id]);
            }
            
            ++e;
        }
        
        return ans;
        
    }
};