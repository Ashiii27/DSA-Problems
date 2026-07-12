class Solution:
    def countSubmatrices(self, g: List[List[int]], k: int) -> int:
        return sum(q<=k for c in zip(*map(accumulate,g)) for q in accumulate(c))