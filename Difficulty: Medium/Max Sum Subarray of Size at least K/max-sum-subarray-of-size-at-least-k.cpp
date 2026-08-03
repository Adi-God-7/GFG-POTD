class Solution {
  public:
    int maxSumWithK(vector<int>& arr, int k) {
        int n = arr.size();

        vector<int> bestEnd(n);
        bestEnd[0] = arr[0];

        for (int i = 1; i < n; i++) {
            bestEnd[i] = max(arr[i], bestEnd[i - 1] + arr[i]);
        }

        int windowSum = 0;
        for (int i = 0; i < k; i++)
            windowSum += arr[i];

        int ans = windowSum;

        for (int i = k; i < n; i++) {
            windowSum += arr[i] - arr[i - k];

            ans = max(ans, windowSum);

            ans = max(ans, windowSum + bestEnd[i - k]);
        }

        return ans;
    }
};