class Solution:
    def minMoves2(self, nums: list[int]) -> int:
        nums.sort()
        mean = nums[len(nums) // 2]
        return sum(abs(mean - i) for i in nums)