class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int w, int wt[], int val[], int n) 
    { 
       vector<vector<int> > dp(n ,vector<int>(w+1,0));
       
       for(int cap=wt[0]; cap<w; cap++) {
           if(wt[0] <= w) 
               dp[0][cap] = val[0];
           else
               dp[0][cap] = 0;
       }
       
       for(int i=1; i<n; i++) {
           for(int cap=0; cap<=w; cap++) {
               int incl = 0;
               
               if(wt[i] <= w) {
                   incl = val[i] + dp[i-1][cap-wt[i]];
                   int excl = 0 + dp[i-1][cap];
                   
                   dp[i][cap] = max(incl, excl);
               }
           }
       }
       
       return dp[n-1][w];
    }
};
