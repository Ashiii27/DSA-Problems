class Solution {
public:
    int maximumLengthSubstring(string s) {
        int left = 0;
        int right = 0;
        int res = 0;
        int freq[26] = {0};
        while(right<s.length()){
            char ch = s[right];
            freq[ch-'a']++;
            while(freq[ch-'a']>2){
                freq[s[left]-'a']--;
                left++;
            }
            right++;
            res = max(res,right-left);
        }
        return res;
    }
};