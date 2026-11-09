from sortedcontainers import SortedList
from collections import Counter
class Solution:
    def busiestServers(self, k: int, arrival: list[int], load: list[int]) -> list[int]:
        heap = []
        free_servers = SortedList(range(k))
        requests_handled = Counter()
        max_requests = 0

        for idx in range(len(arrival)):
            while heap and heap[0][0] <= arrival[idx]:
                free_servers.add(heap[0][1])
                heapq.heappop(heap)

            target = bisect.bisect_left(free_servers, idx % k)
            if target == len(free_servers):
                target = free_servers[0] if free_servers else -1
            else:
                target = free_servers[target]
            
            if target >= 0:
                free_servers.remove(target)
                heapq.heappush(heap, (arrival[idx] + load[idx], target))
                requests_handled[target] += 1
                if requests_handled[target] > max_requests:
                    max_requests = requests_handled[target]

        return [] if max_requests == 0 else [k for k, v in requests_handled.items() if v == max_requests]