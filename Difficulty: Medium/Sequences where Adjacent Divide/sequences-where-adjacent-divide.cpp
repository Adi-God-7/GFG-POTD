class Solution {
  public:
    int count(int n, int m) {
        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 0));

        for (int i = 1; i <= m; i++)
            dp[1][i] = 1;

        for (int len = 2; len <= n; len++) {
            for (int last = 1; last <= m; last++) {
                for (int prev = 1; prev <= m; prev++) {
                    if (last % prev == 0 || prev % last == 0)
                        dp[len][last] += dp[len - 1][prev];
                }
            }
        }

        long long ans = 0;
        for (int i = 1; i <= m; i++)
            ans += dp[n][i];

        return ans;
    }
};