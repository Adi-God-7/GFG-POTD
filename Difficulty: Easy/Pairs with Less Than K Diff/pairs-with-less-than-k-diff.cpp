class Solution {
  public:
    int countPairs(vector<int>& arr, int k) {
        // code here
       sort(arr.begin(), arr.end());

        int n = arr.size();
        int j = 1;
        int ans = 0;

        for (int i = 0; i < n; i++) {

            if (j <= i)
                j = i + 1;

            while (j < n && arr[j] - arr[i] < k)
                j++;

            ans += (j - i - 1);
        }

        return ans;
    }
};