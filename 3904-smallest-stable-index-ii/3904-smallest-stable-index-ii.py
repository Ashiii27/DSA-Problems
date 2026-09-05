class Solution:
    def firstStableIndex(self, nums: list[int], k: int) -> int:
        n = len(nums)
        maxi = -10**9
        mini = 10**9

        right_mini = [0] * n

        for idx in range(n - 1, -1, -1):
            mini = min(mini, nums[idx])
            right_mini[idx] = mini

        for idx in range(n):
            maxi = max(maxi, nums[idx])
            score = maxi - right_mini[idx]

            if score <= k:
                return idx

        return -1