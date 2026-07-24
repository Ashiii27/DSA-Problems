class Solution:
    def uniqueXorTriplets(self, nums: List[int]) -> int:


        # nums[i] <= 1500, so XOR values are limited to [0, 2047]
        values = set(nums)

        reachable2 = [False]*2048
        reachable3 = [False]*2048

        # Compute all XOR values obtainable using two numbers
        for first in values:
            for second in values:
                reachable2[first^second] = True

        # Extend every reachable pair XOR with a third number
        for xor in range(2048):
            if reachable2[xor]:
                for c in values:
                    reachable3[xor^c] = True

        return sum(reachable3)