class Solution {
public:
    long long maximumSum(vector<vector<int>>& mat, int k) {

        int n = mat.size();

        vector<vector<long long>> prefix(
            n + 1,
            vector<long long>(n + 1, 0)
        );

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {

                prefix[i][j] =
                    mat[i - 1][j - 1]
                    + prefix[i - 1][j]
                    + prefix[i][j - 1]
                    - prefix[i - 1][j - 1];
            }
        }

        long long answer = LLONG_MIN;

        for (int i = 0; i + k <= n; i++) {

            for (int j = 0; j + k <= n; j++) {

                int bottom = i + k;
                int right = j + k;

                long long sum =
                    prefix[bottom][right]
                    - prefix[i][right]
                    - prefix[bottom][j]
                    + prefix[i][j];

                answer = max(answer, sum);
            }
        }

        return answer;
    }
};