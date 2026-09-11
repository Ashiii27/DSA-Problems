class Solution:
    def totalNumbers(self, digits: List[int]) -> int:

        # 1. build counter
        counter = Counter(digits)         # stores {digit: freq}

        res = 0

        # 2. greedily search for valid 'd1d2d3' to build the number
        for d1 in range(1, 10):          # search for the first digit
            # pass
            if counter[d1] == 0:
                continue

            # otherwise; pick d1
            counter[d1] -= 1

            # search for the second digit
            for d2 in range(10): 
                # pass
                if counter[d2] == 0:
                    continue

                # otherwise; pick d2
                counter[d2] -= 1

                # search for the last digit, must be even
                for d3 in range(0, 10, 2): 
                    # pass
                    if counter[d3] == 0:
                        continue

                    # otherwise; pick d3
                    # now we have a valid 'd1d2d3' 
                    res += 1

                # once done, revert back d2
                counter[d2] += 1

            # once done, revert back d1
            counter[d1] += 1

        return res