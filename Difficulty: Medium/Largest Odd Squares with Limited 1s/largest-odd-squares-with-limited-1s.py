class Solution:
    def largestSquare(self, mat: list[list[int]], queries: list[list[int]], k: int) -> list[int]:
        n = len(mat)
        m = len(mat[0])

        pref = [[0] * (m + 1) for _ in range(n + 1)]

        for i in range(n):
            for j in range(m):
                pref[i + 1][j + 1] = (
                    mat[i][j]
                    + pref[i][j + 1]
                    + pref[i + 1][j]
                    - pref[i][j]
                )

        def get_sum(r1, c1, r2, c2):
            return (
                pref[r2 + 1][c2 + 1]
                - pref[r1][c2 + 1]
                - pref[r2 + 1][c1]
                + pref[r1][c1]
            )

        ans = []

        for i, j in queries:
            max_radius = min(i, n - 1 - i, j, m - 1 - j)

            if mat[i][j] > k:
                ans.append(-1)
                continue

            lo = 0
            hi = max_radius
            best = 0

            while lo <= hi:
                mid = (lo + hi) // 2

                r1 = i - mid
                r2 = i + mid
                c1 = j - mid
                c2 = j + mid

                ones = get_sum(r1, c1, r2, c2)

                if ones <= k:
                    best = mid
                    lo = mid + 1
                else:
                    hi = mid - 1

            ans.append(2 * best + 1)

        return ans