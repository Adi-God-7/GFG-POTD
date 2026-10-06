class Solution:
    def longIncPath(self, matrix, n, m):
        from functools import cache
        @cache
        def dfs(x,y):
            nonlocal matrix,n,m
            mx=1
            for dx,dy in [(0,1,),(0,-1,),(1,0,),(-1,0,),]:
                nx=x+dx
                ny=y+dy
                if 0<=nx<m and 0<=ny<n and matrix[ny][nx]>matrix[y][x]:
                    mx=max(mx,dfs(nx,ny)+1)
            return mx
        mx=0
        for y in range(n):
            for x in range(m):
                mx=max(mx,dfs(x,y))
        return mx

