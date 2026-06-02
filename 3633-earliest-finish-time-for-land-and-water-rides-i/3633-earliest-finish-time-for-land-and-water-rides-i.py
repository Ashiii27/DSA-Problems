from math import inf
from typing import List

class Solution:
    def earliestFinishTime(
        self,
        landStartTime: List[int],
        landDuration: List[int],
        waterStartTime: List[int],
        waterDuration: List[int]
    ) -> int:

        def helper(s1, d1, s2, d2):
            op = inf

            # Earliest completion of first ride type
            for i in range(len(s1)):
                op = min(op, s1[i] + d1[i])

            op2 = inf

            # Earliest completion after taking second ride
            for i in range(len(s2)):
                op2 = min(
                    op2,
                    max(op, s2[i]) + d2[i]
                )

            return op2

        lw = helper(
            landStartTime,
            landDuration,
            waterStartTime,
            waterDuration
        )

        wl = helper(
            waterStartTime,
            waterDuration,
            landStartTime,
            landDuration
        )

        return min(lw, wl)