class Solution:
    def minInsertions(self, s: str) -> int:
        unbal_count = 0
        bal = 0
        i = 0
        while i < len(s):
            ch = s[i]
            if ch == ')':
                if i+1 <len(s) and s[i+1] == ')':
                    if bal > 0:
                        bal -=1 
                    else:
                        unbal_count += 1
                    i+=1
                elif bal > 0:
                    unbal_count += 1
                    bal -=1 
                else:
                    unbal_count += 2
            else:
                bal += 1
            i+=1
        return unbal_count + bal * 2   