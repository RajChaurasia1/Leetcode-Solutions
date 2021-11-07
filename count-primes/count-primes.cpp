class Solution {
public:
    int countPrimes(int n) {
        
        if(n <= 1)
            return 0;
        
        vector<int>prime(n + 1, 1);
        
        prime[0] = 0, prime[1] = 0;
        
        for(int i = 2 ; i * i <= n ; i++){
            if(prime[i]){
            for(int j = i; j * i <= n ; j++){
                prime[i * j] = 0;
            }
        }
        }
        
        int ans = 0;
        
        for(auto i : prime)
            if(i)
                ans++;
        if(prime[n])
            --ans;
        return ans;
        
    }
};