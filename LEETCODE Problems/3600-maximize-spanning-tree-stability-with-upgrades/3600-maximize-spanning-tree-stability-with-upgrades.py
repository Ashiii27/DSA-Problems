class Solution:
    def maxStability(self, n: int, edges: List[List[int]], k: int) -> int:
        parent = list(range(n))

        def find(u: int) -> int:
            if parent[u] == u: return u
            parent[u] = find(parent[u])
            return parent[u]
        
        def union(u: int, v: int) -> bool:
            ru, rv = find(u), find(v)
            if ru == rv: return False

            parent[ru] = rv
            return True

        if len(edges) < n - 1: return -1
        
        must_edges = [(u, v, s) for u, v, s, m in edges if m == 1]

        remaining, min_must_cost = n - 1, inf
        for u, v, s in must_edges:
            if not union(u, v): return -1
            remaining -= 1
            min_must_cost = min(min_must_cost, s)

        if remaining == 0: return min_must_cost

        upgradeable_edges = [(u, v, s) for u, v, s, m in edges if m == 0]
        upgradeable_edges.sort(key= lambda edge: edge[2], reverse=True)

        upgrage_added = [None] * remaining
        for u, v, s in upgradeable_edges:
            if not union(u, v): continue
            remaining -= 1

            upgrage_added[remaining] = s
            if remaining == 0: break

        if remaining > 0: return -1

        if k >= len(upgrage_added): return min(min_must_cost, 2 * upgrage_added[0])

        return min(min_must_cost, 2 * upgrage_added[0], upgrage_added[k])