class Solution:
    def maxSelectedElements(self, nums: List[int]) -> int:
        nums.sort()
        n = len(nums)
        dp = [[1, 1] for _ in range(n)]
        j = 0
        for i, num in enumerate(nums[1:], 1):
            i1 = i - 1
            previous = nums[i1]
            if num != previous:
                j = i1
            if num == previous:
                dp[i][1] = dp[i1][0] + 1
                if num == nums[j] + 1:
                    dp[i][0] = dp[j][0] + 1
                if num == nums[j] + 2:
                    dp[i][0] = dp[j][1] + 1
            elif num == previous + 1:
                dp[i][0] = dp[i1][0] + 1
                dp[i][1] = dp[i1][1] + 1
            elif num == previous + 2:
                dp[i][0] = dp[i1][1] + 1
        return max(d[0] if d[0] > d[1] else d[1] for d in dp)