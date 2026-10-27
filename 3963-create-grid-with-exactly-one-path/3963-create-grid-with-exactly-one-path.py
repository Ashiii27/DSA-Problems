class Solution:
    def createGrid(self, m: int, n: int) -> list[str]:
        top = "."*n
        rest = "#"*(n-1) + "."
        return [top] + [rest] * (m-1)