class Solution {
public:
    int countSubstrings(string S) {
    int N = S.size();
    bool dp[N][N];
    int ans = 0;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0, k = i; k < N; j++,k++){
            if(i == 0)
            dp[j][k] = true;
            else if(i == 1){
                if(S[j] == S[k])
                dp[j][k] = true;
                else
                dp[j][k] = false;
            }
            else{
                if(S[j] == S[k] && dp[j+1][k-1] == true)
                dp[j][k] = true;
                else
                dp[j][k] = false;
            }
            
            if(dp[j][k])
            ans++;
        }
    }
    return ans;
    }
};