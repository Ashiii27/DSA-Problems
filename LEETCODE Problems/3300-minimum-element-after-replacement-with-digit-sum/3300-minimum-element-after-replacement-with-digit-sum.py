class Solution:
    def minElement(self, nums):

        def digitSum(num):
            total = 0

            while num > 0:
                total += num % 10
                num //= 10

            return total

        ans = float('inf')

        for num in nums:
            ans = min(ans, digitSum(num))

        return ans