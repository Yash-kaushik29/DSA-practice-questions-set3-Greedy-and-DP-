# Approach 

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        int n=days.size();
        vector<int> dp(n+1, INT_MAX);

        dp[n]=0;

        for(int i=n-1; i>=0; i--) {
            int op1 = costs[0] + dp[i+1];

            int j;
            for(j=i; j<n && days[j] < days[i]+7; j++);
            int op2 = costs[1] + dp[j];

            for(j=i; j<n && days[j] < days[i]+30; j++);
            int op3 = costs[2] + dp[j];

            dp[i] = min({op1, op2, op3});
        }

        return dp[0];
    }
};

# Space optimization

int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        queue<pair<int, int>> month;
        queue<pair<int, int>> week;
        int ans=0;

        for(int day: days) {
            // Step 1: Remove expired days
            while(!month.empty() && month.front().first+30 <= day) month.pop();

            while(!week.empty() && week.front().first+7 <= day) week.pop();

            // Step 2: Update cost for current day
            month.push({day, ans + costs[2]});
            week.push({day, ans + costs[1]});

            // Step 3: update ans
            ans = min({ans+costs[0], week.front().second, month.front().second});
        }

        return ans;
}
