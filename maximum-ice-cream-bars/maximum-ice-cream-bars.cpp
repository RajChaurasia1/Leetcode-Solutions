class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(begin(costs),end(costs));
        long long ans = 0, price = 0;
        for(auto i : costs){
            price += i;
            if(coins >= price)
                ans++;
            else
                break;
        }
        
        return ans;
    }
};