class Solution:
    def shortestPath(self, n: int, edges: List[List[int]], labels: str, k: int) -> int:
        d = defaultdict(list)
        for u, v, w in edges:
            d[u].append((v, w))
        inf = float("inf")
        h = [(0, 1, 0)]
        vertex = [[inf] * (k + 1) for _ in range(n)]
        while h:
            w, cnt, u = heappop(h)
            if u == n - 1:
                return w
            for v, m in d[u]:
                nxt_cnt = cnt + 1 if labels[u] == labels[v] else 1
                if nxt_cnt <= k:
                    nxt_w = w + m
                    if nxt_w < vertex[v][nxt_cnt]:
                        vertex[v][nxt_cnt] = nxt_w
                        heappush(h, (nxt_w, nxt_cnt, v))
        return -1