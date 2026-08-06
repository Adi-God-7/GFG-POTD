class Solution {
public:
    int countMinOperations(vector<int>& arr) {
        int cnt = 0;

        while (true) {
            bool allZero = true;

            for (int i = 0; i < arr.size(); i++) {
                if (arr[i] != 0)
                    allZero = false;

                if (arr[i] % 2 == 1) {
                    arr[i]--;
                    cnt++;
                }
            }

            if (allZero)
                break;

            bool hasNonZero = false;
            for (int i = 0; i < arr.size(); i++) {
                if (arr[i] != 0) {
                    hasNonZero = true;
                    break;
                }
            }

            if (hasNonZero) {
                for (int i = 0; i < arr.size(); i++)
                    arr[i] /= 2;
                cnt++;
            }
        }

        return cnt;
    }
};