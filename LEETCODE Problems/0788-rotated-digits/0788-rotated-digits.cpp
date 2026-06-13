class Solution {
private:
    static constexpr bool good[10] = {
        false, false, true, false, false, true, true, false, false, true
    };
    static constexpr bool invalid[10] = {
        false, false, false, true, true, false, false, true, false, false
    };
public:
    int rotatedDigits(int n) {
        int res = 0;
        for (int i = 2; i <= n; ++i) {
            int x = i;
            bool seenGood = false;
            bool ok = true;
            while (x) {
                int d = x % 10;
                if (invalid[d]) { 
                    ok = false; 
                    break; 
                }
                if (good[d]) seenGood = true;
                x /= 10;
            }
            if (ok && seenGood) ++res;
        }
        return res;
    }
};