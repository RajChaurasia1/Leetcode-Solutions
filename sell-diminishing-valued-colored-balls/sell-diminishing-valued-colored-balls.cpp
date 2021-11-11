class Solution {
public:
    
    int mod = 1e9 + 7;
    
    int maxProfit(vector<int>& inventory, int orders) {

        sort(begin(inventory),end(inventory));
        
        long long int n = inventory.size(), ans = 0;
        
        for(int i = n - 1 ; i >= 0 ; i--){
            long long int diff = inventory[i] - (i > 0 ? inventory[i - 1] : 0);
            long long int order_now = min((long long int)orders,(n - i)*diff);
            long long int r = inventory[i];
            long long int l = r - (order_now/(n - i));
            ans += ((r*(r + 1))/2 - (l*(l + 1))/2)*(n - i);
            ans %= mod;
            ans += l*((order_now) % (n - i));
            ans %= mod;
            orders -= order_now;
        }
        
        
        return ans;
    }
};