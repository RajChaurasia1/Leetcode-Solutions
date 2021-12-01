class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0,h = nums.size() - 1,mid, n = nums.size();
        
        
//         while(h > l){
//              mid = l + (h - l)/2;
//             if(nums[mid] == nums[h])
//                 h--;
//              else if(nums[mid] > nums[h]){
//                 l = mid + 1;
                
//             }
//             else
//                 h = mid;
            
//         }
        
        
//         cout << l << endl;
//         if(l == 0)
//             h = n - 1;
//         else{
//             h = (l - 1);
//         }
        
//         cout << l << " " << h;
        
//         if(l == h && nums[l] == target)
//             return l;
//         else if(l == h && nums[l] != target)
//             return -1;
            
        
//         while(l <= h){
//             mid = l + (h - l)/2;
//             if(nums[mid] == target)
//                 return mid;
//             else if(nums[mid] > target){
//                 h = (h + n - 1) % n;
                
//             }
//             else{
//                 l = (l + 1) % n;
//             }
//         }
//         return -1;
        
        
        while(l <= h){
            mid = l + (h - l)/2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] >= nums[l]){
                if(nums[l] <= target && nums[mid] > target)
                    h = mid - 1;
                else
                    l = mid + 1;
            }
            else{
                if(target > nums[mid] && target <= nums[h])
                    l = mid + 1;
                else
                    h = mid - 1;
            }
        }
        return -1;
    }
};