class Solution:
    def longestSubseq(self, arr):
        dp = {}

        ans = 1

        for x in arr:
            dp[x] = 1 + max(dp.get(x - 1, 0),
                            dp.get(x + 1, 0))

            ans = max(ans, dp[x])

        return ans