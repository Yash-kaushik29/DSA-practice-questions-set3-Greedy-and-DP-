// Recursion + Memoization

int solve(int idx, int price[], int n, vector<vector<int>>& dp) {
    if(idx == 0) {
       return n * price[0];
    }
        
    if(dp[idx][n] != -1) return dp[idx][n];
        
    int exclude = 0 + solve(idx-1, price, n, dp);
    int include = INT_MIN;
    int rodLength = idx+1;
        
    if(rodLength <= n) {
       include = price[idx] + solve(idx, price, n-rodLength, dp);
    }
        
    return dp[idx][n] = max(include, exclude);
}
    
int cutRod(int price[], int n) {
   vector<vector<int>> dp(n, vector<int>(n+1, -1));
   return solve(n-1, price, n, dp);
}

// Tabulation

int cutRod(int price[], int n) {
    vector<vector<int>> dp(n, vector<int>(n+1, -1));
        
    for(int N=0; N<=n; N++) {
        dp[0][N] = N * price[0];
    }
        
    for(int idx=1; idx<n; idx++) {
       for(int N=0; N<=n; N++) {
           int exclude = 0 + dp[idx-1][N];
           int include = INT_MIN;
           int rodLength = idx+1;
        
           if(rodLength <= N) {
              include = price[idx] + dp[idx][N-rodLength];
           }
        
           dp[idx][N] = max(include, exclude);
       }
    }
        
    return dp[n-1][n];
}

// Space Optimization

int cutRod(int price[], int n) {
    vector<int> prev(n+1, 0);
        
    for(int N=0; N<=n; N++) {
        prev[N] = N * price[0];
    }
        
    for(int idx=1; idx<n; idx++) {
       for(int N=0; N<=n; N++) {
        
           int exclude = 0 + prev[N];
           int include = INT_MIN;
           int rodLength = idx+1;
        
           if(rodLength <= N) {
              include = price[idx] + prev[N-rodLength];
           }
        
           prev[N] = max(include, exclude);
       }
    }
        
    return prev[n];
}
