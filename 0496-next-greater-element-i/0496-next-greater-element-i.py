class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        res = []
        for target in nums1:
            neg = -1
            target_found = False
            for num in nums2:
                if num == target:
                    target_found = True
                elif target_found:
                    if num > target:
                        neg = num
                        break
            res.append(neg)
        
        return res