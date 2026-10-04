class Solution:
    def checkValidString(self, s):
        bal = 0
        for ch in s:
            bal += 1 if ch in '(*' else -1
            if bal < 0:
                return False

        bal = 0
        for ch in reversed(s):
            bal += 1 if ch in ')*' else -1
            if bal < 0:
                return False

        return True