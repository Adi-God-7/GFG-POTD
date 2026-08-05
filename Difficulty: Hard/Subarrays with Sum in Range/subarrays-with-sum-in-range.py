class Solution:
    def count(self, arr, m):
        t = 0
        l = 0
        res = 0
        for ind, i in enumerate(arr):
            t += i
            while t > m:
                t -= arr[l]
                l += 1
            res += ind - l
        return res

    def countSubarray(self, arr: list[int], l: int, r: int) -> int:
        # code here
        return self.count(arr, r) - self.count(arr, l-1)