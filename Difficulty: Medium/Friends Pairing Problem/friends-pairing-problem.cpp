class Solution {
public:
    int countFriendsPairings(int n) {
        long long dp[19] = {};
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= n; i++)
            dp[i] = dp[i - 1] + (i - 1) * dp[i - 2];

        return dp[n];
    }
};