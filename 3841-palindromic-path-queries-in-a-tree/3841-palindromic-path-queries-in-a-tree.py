class Tree:
    def __init__(self, n: int, f: 'function', z: object):
        self.t = [z for _ in range(2*n)]
        self.n, self.f, self.z = n, f, z
    def update(self, i: int, v: object):
        self[i] = v
    def query(self, i: int, j: int):
        return self[i:j]
    def __setitem__(self, i: int, v: object):
        i += self.n
        self.t[i] = v
        while i > 1:
            i //= 2
            self.t[i] = self.f(self.t[i*2], self.t[i*2+1])
    def __getitem__(self, k: int | slice) -> object:
        if type(k) is int: return self.t[k + self.n]
        l, r, _ = k.indices(self.n)
        L, R = self.z, self.z
        l += self.n
        r += self.n
        while l < r:
            if l&1: L = self.f(L, self.t[l]); l += 1
            if r&1: r -= 1; R = self.f(self.t[r], R)
            l //= 2
            r //= 2
        return self.f(L, R)

class HeavyLight:
    def __init__(self, n, f, z):
        self.timer, self.A = 0, [[] for _ in range(n)]
        # parent, depth, size, visit time
        self.P, self.D, self.sz, self.V = [0]*n, [0]*n, [0]*n, [0]*n
        self.R = list(range(n))  # root
        self.tr = Tree(n, f, z)
    def add(self, i, j):
        self.A[i].append(j); self.A[j].append(i)
    def dfs_sz(self, i, p=-1):
        self.sz[i] = 1
        A, P, D, sz = self.A, self.P, self.D, self.sz
        for j in A[i]:
            if j != p:
                P[j], D[j] = i, D[i] + 1
                self.dfs_sz(j, i)
                sz[i] += sz[j]
    def dfs_hl(self, i, p=-1):
        self.V[i], self.timer = self.timer, self.timer + 1
        A, sz, R = self.A, self.sz, self.R
        C = [j for j in A[i] if j != p]
        if C:
            k = max(C, key=sz.__getitem__)
            h = A[i].index(k)
            A[i][0], A[i][h] = A[i][h], A[i][0]
            R[k] = R[i]
        for j in A[i]:
            if j != p: self.dfs_hl(j, i)
    def update(self, i, v):
        self.tr.update(self.V[i], v)
    def query(self, i, j):
        assert self.timer
        res = self.tr.z
        R, D, P, V, tr = self.R, self.D, self.P, self.V, self.tr
        while R[i] != R[j]:
            if D[R[i]] < D[R[j]]: i, j = j, i
            res = tr.f(res, tr.query(V[R[i]], V[i]+1))
            i = P[R[i]]
        if D[i] < D[j]: i, j = j, i
        return tr.f(res, tr.query(V[j], V[i]+1))

class Solution:
    def palindromePath(self, n: int, edges: list[list[int]], s: str, queries: list[str]) -> list[bool]:
        
        g = HeavyLight(n, xor, 0)  
        for i, j in edges:
            g.add(i, j)
        
        g.dfs_sz(0)
        g.dfs_hl(0)
        for i, c in enumerate(s):
            g.update(i, 1 << ord(c)-ord('a'))
        
        
        res = []
        for q in queries:
            t, *args = q.split()
            if t == 'update':
                i = int(args[0])
                c = args[1]
                g.update(i, 1 << ord(c)-ord('a'))
                continue
            i = int(args[0])
            j = int(args[1])
            res.append(g.query(i, j).bit_count() <= 1)
        return res