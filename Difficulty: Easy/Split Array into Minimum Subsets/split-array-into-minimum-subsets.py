class Solution:
    def minSubsets(self, arr):
        #code here
        c=1
        arr=sorted(arr)
        for i in range(len(arr)-1):
            if (arr[i]+1!=arr[i+1]):
                c+=1
        return c