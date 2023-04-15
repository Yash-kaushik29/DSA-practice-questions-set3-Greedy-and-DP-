class Solution {
public:
    int solve(int i, int k, vector<vector<int>>& piles, vector<vector<int>>& dp) {
        
        if(i>=piles.size() || k==0) 
          return 0;

        if(dp[i][k] != -1)
          return dp[i][k];

        int res = solve(i+1, k, piles, dp);
        int curr = 0;

        for(int j=0; j<piles[i].size() and j<k; j++) {
            curr+=piles[i][j];
            res = max(res, curr + solve(i+1, k-j-1, piles, dp));
        }  

        dp[i][k] = res;
        return res;
    }

    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        vector<vector<int>> dp(n+1, vector<int> (k+1,-1));

        return solve(0, k, piles, dp);
    }
};
