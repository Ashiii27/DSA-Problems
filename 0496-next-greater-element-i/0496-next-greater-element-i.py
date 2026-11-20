class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        stack = []       
        greater = {}    

        for n in nums2:
            while len(stack) and stack[-1] < n:
                greater[stack.pop()] = n
            stack.append(n)
        return [greater.get(n, -1) for n in nums1]