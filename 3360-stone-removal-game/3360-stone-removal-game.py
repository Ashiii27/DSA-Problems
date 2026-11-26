class Solution:
    def canAliceWin(self, n: int) -> bool:
        sub = 10
        alice_turn = True
        while sub>0 and n >= sub:
            n -= sub
            sub -= 1
            alice_turn = not alice_turn
        return not alice_turn
