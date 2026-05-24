class Solution:
    def solve(self, nums, d, i, dp):
        if dp[i] != -1:
            return dp[i]

        # cnt is the maximum number of indices
        # we can visit starting from current index
        cnt = 1

        # Move left
        for jump in range(1, d + 1):
            if i - jump < 0:
                break

            if nums[i] > nums[i - jump]:
                cnt = max(cnt, 1 + self.solve(nums, d, i - jump, dp))
            else:
                break

        # Move right
        for jump in range(1, d + 1):
            if i + jump >= len(nums):
                break

            if nums[i] > nums[i + jump]:
                cnt = max(cnt, 1 + self.solve(nums, d, i + jump, dp))
            else:
                break

        dp[i] = cnt
        return cnt

    def maxJumps(self, arr, d):
        n = len(arr)

        # DP array for memoization
        dp = [-1] * n

        ans = 0

        # Try every index as starting point
        for i in range(n):
            ans = max(ans, self.solve(arr, d, i, dp))

        return ans