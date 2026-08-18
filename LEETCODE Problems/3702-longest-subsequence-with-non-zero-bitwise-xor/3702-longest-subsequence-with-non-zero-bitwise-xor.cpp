class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int total = 0;
        bool hasNonZero = false;

        for(int x:nums) {
            total ^= x;
            if(x!=0) hasNonZero = true;
        }

        if(!hasNonZero) return 0;
        if(total != 0) return nums.size();

        return nums.size()-1;
    }
};