class Solution {
public:
    int maxSubsetXOR(vector<int>& arr) {

        const int B = 20;
        vector<int> basis(B + 1, 0);

        for (int x : arr) {

            int num = x;

            for (int b = B; b >= 0; b--) {

                if (!(num & (1 << b)))
                    continue;

                if (!basis[b]) {
                    basis[b] = num;
                    break;
                }

                num ^= basis[b];
            }
        }

        int ans = 0;

        for (int b = B; b >= 0; b--) {

            if ((ans ^ basis[b]) > ans)
                ans ^= basis[b];
        }

        return ans;
    }
};