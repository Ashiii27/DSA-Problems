from collections import defaultdict
class Solution:
    def maxNumberOfFamilies(self, n: int, reservedSeats: List[List[int]]) -> int:
        booked=defaultdict(lambda: [True,True,True])

        for x,y in reservedSeats:
            if y==1 or y==10:
                continue
            elif y==2 or y==3:
                booked[x][0]=False
            elif y==4 or y==5:
                booked[x][1]=False
                booked[x][0]=False
            elif y==6 or y==7:
                booked[x][1]=False
                booked[x][2]=False
            else:
                booked[x][2]=False


        
        res=2*(n-len(booked))
        for p1,p2,p3 in booked.values():
            if p1 and p2 and p3:
                res+=2
            elif p1 or p2 or p3:
                res+=1

        return res

        