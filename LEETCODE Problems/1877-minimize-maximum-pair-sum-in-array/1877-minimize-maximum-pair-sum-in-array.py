class Solution:
    def minPairSum(self, nums: List[int]) -> int:
        nums.sort()
        i = 0
        j = len(nums) - 1
        pair_sum = []

        while i < j:
            pair_sum.append(nums[i] + nums[j])
            i += 1
            j -= 1

        return max(pair_sum)
