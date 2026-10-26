class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26, 0);
        int l = 0, maxFreq = 0, longest = 0;
        for (int r = 0; r < s.size(); r++) {
            maxFreq = max(maxFreq, ++count[s[r]-'A']);
            if ((r - l + 1) - maxFreq > k) {
                count[s[l]- 'A']--;
                l++;
            }
            longest = max(longest, r - l + 1);
        }
        return longest;
    }
};
