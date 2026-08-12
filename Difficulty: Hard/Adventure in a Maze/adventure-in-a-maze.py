class Solution:
     def findWays(self, grid):
        from functools import cache
        MODULO = 10**9 + 7
        n = len(grid)

        @cache
        def dfs(x: int=0, y: int=0) -> tuple[int, int]:
            if x == y == n - 1:
                return (1, grid[x][y])
            paths = max_adv = 0
            if y < n - 1 and grid[x][y] & 1:
                p, ma = dfs(x, y + 1)
                paths += p
                max_adv = ma
            if x < n - 1 and grid[x][y] & 2:
                p, ma = dfs(x + 1, y)
                paths += p
                max_adv = max(max_adv, ma)
            if max_adv:
                return paths % MODULO, max_adv + grid[x][y]
            else:
                return (0, 0)

        return dfs()   