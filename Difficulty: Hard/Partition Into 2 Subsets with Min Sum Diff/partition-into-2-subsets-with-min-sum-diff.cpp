class Solution {
public:
    int minDifference(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;
        for(auto i : arr) sum += i;

        vector<vector<bool>> dp(n, vector<bool>(sum+1, false));
        for(int i = 0; i < n; i++) dp[i][0] = true;
        if(arr[0] <= sum) dp[0][arr[0]] = true;

        for(int i = 1; i < n; i++){
            for(int target = 1; target <= sum; target++){
                bool skip = dp[i-1][target];
                bool take = (arr[i] <= target) ? dp[i-1][target-arr[i]] : false;
                dp[i][target] = skip | take;
            }
        }
        for(int s = sum/2; s >= 0; s--){
            if(dp[n-1][s]){
                return abs(sum - 2*s);
            }
        }
        return 0;
    }
};