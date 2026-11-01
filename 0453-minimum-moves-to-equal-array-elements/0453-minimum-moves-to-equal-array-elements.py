class Solution:
    def minMoves(self, nums: list[int]) -> int:
        s = sum(nums)
        n = len(nums)
        m = min(nums)

        ans = s - n * m
        return ans

        