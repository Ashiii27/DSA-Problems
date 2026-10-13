class Solution:
    def maxAlternatingSum(self, nums: List[int]) -> int:
        nums=[x*x for x in nums]
        nums.sort(reverse=True)
        n=len(nums)
        half=ceil(n/2)
        sum1=0
        sum2=0
        for i in range(0,half):
            sum1+=nums[i]
        for j in range(half,n):
            sum2+=nums[j]
        return sum1-sum2