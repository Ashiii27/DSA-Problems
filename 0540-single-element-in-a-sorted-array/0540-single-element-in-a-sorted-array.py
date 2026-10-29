class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        n = len(nums)
        start, end = 0, n - 1

        if n == 1:
            return nums[0]

        while start <= end:
            mid = (start + end) // 2

            # edge cases: first and last element
            if mid == 0 and nums[0] != nums[1]:
                return nums[mid]
            if mid == n - 1 and nums[n - 1] != nums[n - 2]:
                return nums[mid]

            # mid has no twin -> it is the answer
            if nums[mid - 1] != nums[mid] and nums[mid] != nums[mid + 1]:
                return nums[mid]

            if mid % 2 == 0:
                # even index, twin on the left -> pairs are shifted -> go left
                if nums[mid - 1] == nums[mid]:
                    end = mid - 1
                # even index, twin on the right -> pairs are normal -> go right
                else:
                    start = mid + 1
            else:
                # odd index, twin on the left -> pairs are normal -> go right
                if nums[mid - 1] == nums[mid]:
                    start = mid + 1
                # odd index, twin on the right -> pairs are shifted -> go left
                else:
                    end = mid - 1
        return -1