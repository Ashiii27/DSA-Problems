class Solution:
    def findMissingAndRepeatedValues(self, grid):
        n = len(grid)
        n2 = n * n
        
        S = (n2 * (n2 + 1)) // 2  
        P = (n2 * (n2 + 1) * (2 * n2 + 1)) // 6  
        
        S_actual, P_actual = 0, 0
        
        for row in grid:
            for num in row:
                S_actual += num
                P_actual += num * num
        
        diff1 = S_actual - S  
        diff2 = P_actual - P  
        
        sum_ab = diff2 // diff1  
        
        a = (diff1 + sum_ab) // 2
        b = sum_ab - a
        
        return [a, b]