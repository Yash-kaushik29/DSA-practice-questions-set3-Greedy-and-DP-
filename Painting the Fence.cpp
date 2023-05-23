class Solution{
    public:
    #define mod 1000000007
    #define ll long long
    
    ll add(ll a, ll b) {
        return (a%mod + b%mod)%mod;
    }
    
    ll mul(ll a, ll b) {
        return ((a%mod)*(b%mod)) % mod;
    }
    
    long long countWays(int n, int k){
        vector<ll> dp(n+1,-1);
        
        dp[1] = k;
        dp[2] = add(k, mul(k, k-1));
        
        for(int i=3; i<=n; i++) {
            dp[i] = add(mul(dp[i-2], k-1), mul(dp[i-1], k-1));
        }
        return dp[n];
    }
};
