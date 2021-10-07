class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        int n = arr.size(), ones = 0, cnt = 0;
        for(int i = 0 ; i < n ; i++){
            if(arr[i])
                ones++;
        }
        
        if(ones == 0)
            return {0,n - 1};
        if(ones%3!=0)
            return {-1,-1};
        
        int k = ones/3, frst, scnd, thrd;
        
        for(int i = 0 ; i < n ; i++){
            if(arr[i]){
                frst = i;
                break;
            }
                
        }
        
        cnt = 0;
        
        
        for(int i = frst + 1 ; i < n ; i++){
            if(arr[i])
                cnt++;
            if(arr[i] && cnt == k){
                scnd = i;
                break;
            }
                
        }
        
        cnt = 0;
        
        for(int i = scnd + 1 ; i < n ; i++){
            if(arr[i])
                cnt++;
            if(arr[i] && cnt == k){
                thrd = i;
                break;
            }
                
        }
        
        
        int x = frst, y = scnd, z = thrd;
        
        while(x < n && y < n && z < n){
            if(arr[x] == arr[y] && arr[y] == arr[z]){
                x++;y++;z++;
            }
            else
                return {-1,-1};
        }
        
        return {x - 1, y};
      
    }
};