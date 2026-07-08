class Solution {
public:
    int reverseBits(int n) {
        int res = 0;
        uint cur = 31;

        while (n) {
            if (n & 1) {
                res += 1 << cur;
            }
            --cur;
            n >>= 1;
        }
        return res;
    }
};