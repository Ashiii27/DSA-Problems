gen = 0
depth = [0] * 100_001
pow2 = [0] * 100_001
pow2[1] = 1
for i in range(2, 100_001):
    pow2[i] = (pow2[i - 1] * 2) % 1_000_000_007


class Solution:
    def assignEdgeWeights(self, edges, queries) -> List[int]:
        global gen
        gen += 1 << 18

        g = defaultdict(list)
        for u, v in edges:
            g[min(u, v)].append(max(u, v))

        q = defaultdict(list)
        for i, (u, v) in enumerate(queries):
            q[u].append((v, i))
            q[v].append((u, i))

        n = len(edges) + 1
        uf = list(range(n + 1))
        lca = [0] * len(queries)

        def find(x):
            while uf[x] != x:
                uf[x] = uf[uf[x]]
                x = uf[x]
            return x

        def tarjan(u: int):
            for v in g[u]:
                depth[v] = depth[u] + 1
                tarjan(v)
                uf[v] = u
            for v, i in q[u]:
                if depth[v] >= gen:
                    lca[i] = find(v)

        depth[1] = gen
        tarjan(1)

        return [
            pow2[depth[u] + depth[v] - 2 * depth[lca[i]]]
            for i, (u, v) in enumerate(queries)
        ]