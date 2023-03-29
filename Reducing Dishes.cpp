class Solution {
public:
    int solve(vector< int> &nums, int i, int j, vector<vector<int>> &dp){

        if(i==nums.size()){
            return 0;
        }
        if(dp[i][j]!=-1) 
            return dp[i][j];
            
        int pick = j*nums[i] + solve(nums, i+1, j+1, dp);
        int notpick = solve(nums,i+1,j,dp);

        return dp[i][j] = max(pick,notpick);
    }

    int maxSatisfaction(vector<int>& sat) {

        int n = sat.size();
        sort(sat.begin(),sat.end());
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));

        return solve(sat,0,1,dp);
    }
};
