class Solution {
  public:
    int findMax(int n) {
        int bestNumber = n;

        int temp = n;
        int bestSum = 0;

        while (temp > 0) {
            bestSum += temp % 10;

            temp /= 10;
        }

        int digits = 0;
        temp = n;

        while (temp > 0) {
            digits++;
            temp /= 10;
        }

        int power = 1;

        for (int i = 1; i < digits; i++) {
            power *= 10;
        }

        int prefix = 0;

        int prefixSum = 0;

        temp = n;

        for (int i = 0; i < digits; i++) {
            int digit = (temp / power) % 10;

            if (digit > 0) {
                int remaining = digits - i - 1;

                int candidateSum =
                    prefixSum + (digit - 1) + 9 * remaining;

                int candidate =
                    prefix * 10 * power +
                    (digit - 1) * power +
                    (power - 1);

                if (candidateSum > bestSum ||
                    (candidateSum == bestSum && candidate > bestNumber)) {
                    bestSum = candidateSum;
                    bestNumber = candidate;
                }
            }

            prefix = prefix * 10 + digit;
            prefixSum += digit;

            power /= 10;
        }

        return bestNumber;
    }
};