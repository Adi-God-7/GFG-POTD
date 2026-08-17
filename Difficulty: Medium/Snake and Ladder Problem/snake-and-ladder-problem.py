from collections import deque

class Solution:
    def minThrows(self, n, lad, sn):
        final = n * n

        jumps = {}

        for i in range(0, len(lad), 2):
            jumps[lad[i]] = lad[i + 1]

        for i in range(0, len(sn), 2):
            jumps[sn[i]] = sn[i + 1]

        visited = [False] * (final + 1)
        visited[1] = True

        q = deque([(1, 0)])

        while q:
            pos, throws = q.popleft()

            if pos == final:
                return throws

            for dice in range(1, 7):
                nxt = pos + dice

                if nxt > final:
                    break

                nxt = jumps.get(nxt, nxt)

                if not visited[nxt]:
                    visited[nxt] = True
                    q.append((nxt, throws + 1))

        return -1