class Solution:
    def isPossible(self, arr, s, x):
        nums = []
        total = s

        if s <= x:
            nums.append(s)

        for v in arr:
            new_value = total + v
            total += new_value

            if new_value <= x:
                nums.append(new_value)

            if total > x and new_value > x:
                break

        if x == 0:
            return True

        if not nums:
            return False

        mid = len(nums) // 2

        left = nums[:mid]
        right = nums[mid:]

        sums = {0}

        for v in left:
            new_sums = set()

            for curr in sums:
                if curr + v <= x:
                    new_sums.add(curr + v)

            sums |= new_sums

        right_sums = {0}

        for v in right:
            new_sums = set()

            for curr in right_sums:
                if curr + v <= x:
                    new_sums.add(curr + v)

            right_sums |= new_sums

        for value in sums:
            if x - value in right_sums:
                return True

        return False