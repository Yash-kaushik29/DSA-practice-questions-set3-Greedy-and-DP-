class Solution
{
    public:
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        vector<int> dp(n+1,-1);
        dp[0]=0;
        
        for(int i=1; i<=n; i++) {
            if(i-x >= 0 && dp[i-x] != -1) {
                dp[i] = max(dp[i], 1+dp[i-x]);
            }
            if(i-y >= 0 && dp[i-y] != -1) {
                dp[i] = max(dp[i], 1+dp[i-y]);
            }
            if(i-z >= 0 && dp[i-z] != -1) {
                dp[i] = max(dp[i], 1+dp[i-z]);
            }
        }
        
        return dp[n] < 0 ? 0 : dp[n];
    }
};
