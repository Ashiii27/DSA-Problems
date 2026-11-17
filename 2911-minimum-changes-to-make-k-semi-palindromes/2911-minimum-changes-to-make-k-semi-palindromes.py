class Solution:
    def minimumChanges(self, s: str, k: int) -> int:
        l = len(s)
        memo = {}
        memo_c = {}

        def dfs(index, p):
            if index == l:
                return math.inf

            if (index, p) in memo:
                return memo[(index, p)]

            if p == 1:
                return getMinChange(index, l - 1)

            min_c = math.inf

            for i in range(index + 1, l - p):
                min_c = min(min_c, getMinChange(index, i) + dfs(i + 1, p - 1))

            memo[(index, p)] = min_c

            return min_c

        def getMinChange(start, end):
            if (start, end) in memo_c:
                return memo_c[(start, end)]

            subl = end - start + 1

            divisors = []

            for i in range(1, subl):
                if i * i > subl:
                    break

                if subl % i != 0:
                    continue

                divisors.append(i)
                if subl // i != i and subl // i != subl:
                    divisors.append(subl // i)


            min_change = subl

            for d in divisors:
                change = set()
                for index in range(d):
                    palin = []

                    for i in range(start + index, end + 1, d):
                        palin.append(i)

                    p1, p2 = 0, len(palin) - 1

                    while p1 < p2:
                        if s[palin[p1]] != s[palin[p2]]:
                            change.add(palin[p1])
                            change.add(palin[p2])

                        p1 += 1
                        p2 -= 1

                min_change = min(min_change, len(change) // 2)

            memo_c[(start, end)] = min_change
            
            return min_change

        return dfs(0, k)