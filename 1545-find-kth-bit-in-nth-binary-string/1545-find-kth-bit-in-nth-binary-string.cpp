class Solution {
public:
    char findKthBit(int n, int k) {
        return solve(n, k, false);
    }

private:
    char solve(int n, int k, bool flipped) {
        if (n == 1) return flipped ? '1' : '0';

        int mid = 1 << (n - 1); // 2^(n-1)

        if (k == mid)
            return flipped ? '0' : '1'; // middle is always '1', apply flip

        if (k < mid)
            return solve(n - 1, k, flipped); // left half: same as S(n-1)

        // Right half: reverse + invert of S(n-1)
        return solve(n - 1, 2 * mid - k, !flipped); // mirror position, invert
    }
};