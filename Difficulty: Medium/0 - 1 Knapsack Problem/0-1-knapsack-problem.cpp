class Solution {
  public:

    int solve(int W, vector<int> &val, vector<int> &wt, int n,
              vector<vector<int>> &dp) {

        // Base condition
        if(n == 0 || W == 0)
            return 0;

        // Already calculated
        if(dp[n][W] != -1)
            return dp[n][W];

        // If current item can be included
        if(wt[n-1] <= W) {
            return dp[n][W] = max(
                val[n-1] + solve(W-wt[n-1], val, wt, n-1, dp),
                solve(W, val, wt, n-1, dp)
            );
        }

        // If current item cannot be included
        return dp[n][W] = solve(W, val, wt, n-1, dp);
    }

    int knapsack(int W, vector<int> &val, vector<int> &wt) {

        int n = val.size();

        vector<vector<int>> dp(n+1, vector<int>(W+1, -1));

        return solve(W, val, wt, n, dp);
    }
};