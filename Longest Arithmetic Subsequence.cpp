// Recursion + Memoization

class Solution{   
public:
    int solve(int idx, int diff, int A[], unordered_map<int, int> dp[]) {
        if(idx < 0) {
            return 0;
        }
        
        if(dp[idx].count(diff)) 
           return dp[idx][diff];
        
        int ans=0;
        for(int j=idx-1; j>=0; j--) {
            if(A[idx]-A[j] == diff) {
                ans = max(ans, 1 + solve(j, diff, A, dp));
            }
        }
        return dp[idx][diff] = ans;
    }

    int lengthOfLongestAP(int A[], int n) {
        if(n <= 2) {
            return n;
        }
        
        unordered_map<int, int> dp[n+1];
        
        int ans=0;
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                
                ans = max(ans, 2 + solve(i, A[j]-A[i], A, dp));
            }
        }
        return ans;
    }
};

// Tabulation 

class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();

        if(n <= 2) 
            return n;
        
        unordered_map<int, int> dp[n+1];
        
        int ans=0;
        
        for(int i=1; i<n; i++) {
            for(int j=0; j<i; j++) {
                int cnt = 1;
                int diff = nums[i]-nums[j];
                
                if(dp[j].count(diff))
                    cnt = dp[j][diff];
                
                dp[i][diff] = 1 + cnt;
                ans = max(ans, dp[i][diff]);
            } 
        }
        
        return ans;
    }
};
