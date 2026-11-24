class Solution:
    def maxLength(self, nums: List[int]) -> int:
        n = len(nums)
        for i in range(n, 0, -1):
            for j in range(n - i + 1):
                arr = nums[j:j + i]
                if math.prod(arr) == reduce(math.lcm, arr) * math.gcd(*arr):
                    return len(arr)