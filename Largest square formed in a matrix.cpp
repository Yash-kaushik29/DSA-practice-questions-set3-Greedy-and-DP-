// Recursion + Memoization

class Solution{
public:
    int solve(int i, int j, int n, int m, vector<vector<int>> mat, int& maxi, vector<vector<int>>& dp) {
        if(i>=n || j>=m) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int right = solve(i, j+1, n, m, mat, maxi, dp);
        int down = solve(i+1, j, n, m, mat, maxi, dp);
        int diagonal = solve(i+1, j+1, n, m, mat, maxi, dp);
        
        if(mat[i][j] == 1) {
            dp[i][j] = 1 + min({right, down, diagonal});
            maxi = max(maxi, dp[i][j]);
            return dp[i][j];
        }else {
            return dp[i][j]=0;
        }
    } 

    int maxSquare(int n, int m, vector<vector<int>> mat){
        int maxi = 0;
        vector<vector<int>> dp(n, vector<int>(m,-1));
        
        solve(0, 0, n, m, mat, maxi, dp);
        return maxi;
    }
};

// Tabulation Method

class Solution{
public:
    int solveTab(int n, int m, vector<vector<int>> mat, int& maxi) {
        vector<vector<int>> dp(n+1, vector<int>(m+1,0));
        
        for(int i=n-1; i>=0; i--) {
            for(int j=m-1; j>=0; j--) {
                int right = dp[i][j+1];
                int down = dp[i+1][j];
                int diagonal = dp[i+1][j+1];
        
                if(mat[i][j] == 1) {
                   dp[i][j] = 1 + min({right, down, diagonal});
                   maxi = max(maxi, dp[i][j]);
                }
                else {
                   dp[i][j]=0;
                }
            }
        }
        
        return dp[0][0];
    }

    int maxSquare(int n, int m, vector<vector<int>> mat){
        
        int maxi=0;
        solveTab(n, m, mat, maxi);
        return maxi;
    }
};

// Space Optimization

class Solution{
public:
    int maxSquare(int n, int m, vector<vector<int>> mat){
        int maxi=0;
        vector<int> currRow(m+1,0);
        vector<int> nextRow(m+1,0);
        
        for(int i=n-1; i>=0; i--) {
            for(int j=m-1; j>=0; j--) {
                
                int right = currRow[j+1];
                int down = nextRow[j];
                int diagonal = nextRow[j+1];
                
                if(mat[i][j] == 1) {
                    currRow[j] = 1 + min({right, down, diagonal});
                    maxi = max(maxi, currRow[j]);
                }
                else {
                    currRow[j]=0;
                }
            }
            nextRow = currRow;
        }
        return maxi;
    }
};
