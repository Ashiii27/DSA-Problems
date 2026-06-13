class Solution(object):
    def leftRightDifference(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        total_sum = sum(nums)
        left_sum = 0
        right_sum = 0
        result = []
        for i in range(len(nums)):
            right_sum = total_sum - left_sum - nums[i]
            result.append(abs(right_sum - left_sum))
            left_sum = left_sum + nums[i]
        return result