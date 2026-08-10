class Solution {
public:
    bool winnerSquareGame(int n) 
    {
        //time complexity: O(n.sqrt(n))
        //space complexity: O(n)

        //dp[i] represents whether the current player can win starting with 'i' stones
        vector<bool> dp(n+1,false);

        for(int i=0;i<=n;i++) 
        {
            //if the current state is a losing position for the current player, they can move to any state (i + j*j) and force the opponent to lose.
            if(!dp[i]) 
            {
                for(int j=1;(i+j*j)<=n;j++)
                    dp[i+j*j]=true;

                //early exit if we already know the target 'n' is a winning position
                if(dp[n]) 
                    return true;
            }
        }
        //otherwise, returning 'false' at last
        return false;
    }
};