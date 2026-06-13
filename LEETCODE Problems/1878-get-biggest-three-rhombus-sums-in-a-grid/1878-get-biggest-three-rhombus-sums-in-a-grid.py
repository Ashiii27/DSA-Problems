class Solution:
    def getBiggestThree(self, grid: List[List[int]]) -> List[int]:
        for row in grid: print(row)
        width = len(grid[0])
        height = len(grid)

        upRight = [[0]*(width + 1) for _ in range(height + 1)]
        downRight = [[0]*(width + 1) for _ in range(height + 1)]
        
        # fill upRight
        for diag in range(width + height - 1):
            y = min(diag, height - 1)
            x = diag - y
            curDiag = 0

            while y >= 0 and x < width:
                curDiag += grid[y][x]
                upRight[y][x + 1] = curDiag
                x += 1
                y -= 1

  
        # fill downRight
        for diag in range(-height + 1, width):
            # diag = x - y
            x = max(diag, 0)
            y = x - diag
            curDiag = 0

            while y < height and x < width:
                curDiag += grid[y][x]
                downRight[y + 1][x + 1] = curDiag
                x += 1
                y += 1




        def getUpRightSum(startX,startY, sideLen):
            return upRight[startY - sideLen + 1][startX + sideLen] - upRight[startY + 1][startX] 
        
        def getDownRightSum(startX,startY, sideLen):
            return downRight[startY + sideLen][startX + sideLen] - downRight[startY][startX]


        def getRhombusSum(startX, startY, sideLen):

            sw = downRight[startY + sideLen][startX + sideLen] - downRight[startY][startX]
            # sw = getDownRightSum(startX, startY, sideLen)
            nw = upRight[startY - sideLen][startX + 1 + sideLen] - upRight[startY][startX + 1] 
            # nw = getUpRightSum(startX + 1, startY - 1, sideLen)
            se = downRight[startY + 1][startX + sideLen + 1 + sideLen] - downRight[startY - sideLen + 1][startX + sideLen + 1]
            # se = getDownRightSum(startX + sideLen + 1, startY - sideLen + 1, sideLen)
            ne = upRight[startY + 1][startX + sideLen + sideLen] - upRight[startY + sideLen + 1][startX + sideLen]
            # ne = getUpRightSum(startX + sideLen, startY + sideLen, sideLen)

            return sw + nw + se + ne
        

        m1 = m2 = m3 = float('-inf')

        for row in grid:
            for x in row:
                if x > m1:
                    m1, m2, m3 = x, m1, m2
                elif x != m1 and x > m2:
                    m2, m3 = x, m2
                elif m1 != x != m2 and x > m3:
                    m3 = x
            
        maxSideLen = ((min(width, height) + 1) // 2)
        # sidelen = a + 1
        for sideLen in range(1, maxSideLen):
            for startY in range(sideLen, height - sideLen):
                for startX in range(0, width - 2* sideLen):
                    sw = downRight[startY + sideLen][startX + sideLen] - downRight[startY][startX]
                    # sw = getDownRightSum(startX, startY, sideLen)
                    nw = upRight[startY - sideLen][startX + 1 + sideLen] - upRight[startY][startX + 1] 
                    # nw = getUpRightSum(startX + 1, startY - 1, sideLen)
                    se = downRight[startY + 1][startX + sideLen + 1 + sideLen] - downRight[startY - sideLen + 1][startX + sideLen + 1]
                    # se = getDownRightSum(startX + sideLen + 1, startY - sideLen + 1, sideLen)
                    ne = upRight[startY + 1][startX + sideLen + sideLen] - upRight[startY + sideLen + 1][startX + sideLen]
                    # ne = getUpRightSum(startX + sideLen, startY + sideLen, sideLen)

                    rSum =  sw + nw + se + ne
                    
                    # print(f"Rhombussum({startX}, {startY}) = {rSum}")
                    if rSum > m1:
                        m1, m2, m3 = rSum, m1, m2
                    elif rSum != m1 and rSum > m2:
                        m2, m3 = rSum, m2
                    elif rSum != m2 and rSum > m3:
                        m3 = rSum

        if m3 != -inf:
            return [m1,m2,m3]
        
        if m2 != -inf:
            return [m1, m2]

        return [m1]
