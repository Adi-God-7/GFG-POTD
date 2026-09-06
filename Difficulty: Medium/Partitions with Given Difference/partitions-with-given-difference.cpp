class Solution {
  public:
    int countPartitions(vector<int>& arr, int diff) {
        int s = 0;
        int n = arr.size();

        for(auto i : arr)
            s += i;

        if(diff > s || (s + diff) % 2 != 0)
            return 0;

        int s1 = (s + diff) / 2;

        vector<vector<int>> dp(n + 1, vector<int>(s1 + 1, 0));

        for(int i = 0; i <= n; i++)
            dp[i][0] = 1;

        for(int i = 1; i <= n; i++) {
            for(int j = 0; j <= s1; j++) {
                dp[i][j] = dp[i-1][j];

                if(arr[i-1] <= j) {
                    dp[i][j] += dp[i-1][j-arr[i-1]];
                }
            }
        }

        return dp[n][s1];
    }
};