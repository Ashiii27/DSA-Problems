class Solution:
    def checkString(self, s: str) -> bool:
        i=0
        while s[i]!='b' and i<len(s)-1:
            i+=1
        while s[i]!='a' and i<len(s)-1:
            i+=1
            if s[i]=='a':
                return False
        return True 