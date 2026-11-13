class Solution:
    def countNonDecreasingSubarrays(self, nums: List[int], k: int) -> int:
        n = len(nums)

        cost = 0
        deque = Deque([])
        result = 0
        last = n - 1
        total = 0

        for i in range(n - 1, -1, -1):

            count = 1
            while deque and deque[-1][0] <= nums[i]:
                curr = deque.pop()
                count += curr[1]
                cost += (nums[i] - curr[0]) * curr[1]
            
            total += 1
            deque.append((nums[i], count))

            while deque and cost > k:
                curr = deque.popleft()
                cnt = curr[1] - 1
                cost -= (curr[0] - nums[last])
                last -= 1
                total -= 1
                if cnt > 0:
                    deque.appendleft((curr[0], cnt))

            
            result += total

        return result