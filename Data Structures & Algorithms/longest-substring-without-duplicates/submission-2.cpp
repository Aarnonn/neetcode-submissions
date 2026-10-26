class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int length = 0;
        if (s.size() <= 1) return s.size();

        int l = 0, r = 1;
        length++;
        unordered_set<char> chars;
        chars.insert(s[l]);

        while (r < s.size()) {
            while (chars.find(s[r]) != chars.end()) {
                chars.erase(s[l]);
                l++;
            }
            chars.insert(s[r]);
            length = max(length, r - l + 1);
            r++;
        }
        return length;
    }
};
