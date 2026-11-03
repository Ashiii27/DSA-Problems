class Solution:
    def minMoves(self, nums: List[int]) -> int:
        m = max(nums)
        sum = 0
        if len(nums) == 1:
            return 0

        for i in range(0,len(nums)):
            diff = m - nums[i]
            sum += diff
        
        return sum
