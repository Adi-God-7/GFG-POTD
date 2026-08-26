class Solution {
public:
    bool equalPartition(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;
        for(int i = 0;i<arr.size();i++){
            sum += arr[i];
        }
        if(sum % 2 != 0){
            return false;
        }
        sum = sum/2;
        vector<vector<bool>> dp(n+1,vector<bool>(sum+1));
        for(int i = 0;i<n+1;i++){
        for(int j = 0;j<sum+1;j++){
            if(i == 0){
                dp[i][j] = false;
            }
            if(j == 0){
                dp[i][j] = true;
            }
        }
        }
        dp[0][0] = true;
        for(int i = 1;i<n+1;i++){
        for(int j = 1;j<sum+1;j++){
            if(arr[i-1] <= j){
                dp[i][j] = max(dp[i-1][j-arr[i-1]],dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
        }
        if(dp[n][sum]){
            return true;
        }
        else{
            return false;
        }
    }
};