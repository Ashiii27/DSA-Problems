class Solution:
    def lexicographicallySmallestArray(self, nums, limit):
        n = len(nums)

        vp = [(nums[i], i) for i in range(n)]

        vp.sort()

        indices = []
        l = 0

        indices.append(vp[0][1])

        for i in range(1, n):

            if vp[i][0] - vp[i - 1][0] <= limit:
                indices.append(vp[i][1])

            else:
                indices.sort()

                for j, idx in zip(range(l, i), indices):
                    nums[idx] = vp[j][0]

                indices = [vp[i][1]]
                l = i

        indices.sort()

        for j, idx in zip(range(l, n), indices):
            nums[idx] = vp[j][0]

        return nums