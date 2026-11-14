class Solution:
    def minimumSumSubarray(self, nums: List[int], l: int, r: int) -> int:
        m = float("inf")
        for i in range(len(nums)):
            c = 0
            for j in range(i,len(nums)):
                c+=nums[j]
                k = j-i+1
                if l<= k <= r and c>0:
                    m  = min(m,c)
        if m!=float("inf"):
            return m
        else:
            return -1
                