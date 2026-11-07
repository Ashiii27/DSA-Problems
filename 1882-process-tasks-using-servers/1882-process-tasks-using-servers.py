class Solution:
    def assignTasks(self, servers: list[int], tasks: list[int]) -> list[int]:
        free = [(w, i) for i, w in enumerate(servers)]
        used = []
        ans = []
        heapify(free)
        d = 0
        for j, t in enumerate(tasks):
            if j > d: 
                d = j
            if used and used[0][0] <= j:
                while used and used[0][0] == j:
                    _, i = heappop(used)
                    heappush(free, (servers[i], i))
            if not free:
                if used[0][0] > d:
                    d = used[0][0]
                while used and used[0][0] == d:
                    _, i = heappop(used)
                    heappush(free, (servers[i], i))
            _, i = heappop(free)
            ans.append(i)
            heappush(used, (d + tasks[j], i))
        return ans