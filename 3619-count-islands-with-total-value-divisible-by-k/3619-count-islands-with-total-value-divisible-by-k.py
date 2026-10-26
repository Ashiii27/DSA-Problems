class Solution:
    def countIslands(self, grid: List[List[int]], k: int) -> int:
        m = len(grid)
        n = len(grid[0])
        ans = 0

        def dfs(i: int, j: int) -> int:
            if (i < 0 or j < 0 or i >= m or j >= n
                    or grid[i][j] <= 0):
                return 0

            total = grid[i][j]
            grid[i][j] = -1

            total += dfs(i - 1, j)
            total += dfs(i + 1, j)
            total += dfs(i, j - 1)
            total += dfs(i, j + 1)

            return total

        for i in range(m):
            for j in range(n):
                if grid[i][j] > 0:
                    total = dfs(i, j)

                    if total % k == 0:
                        ans += 1

        return ans