class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        vector<int> freq(26, 0);
        int l = 0, n = s1.size(), r = l+n-1;
        for (char c : s1) {
            freq[c - 'a']++;
        }

        vector<int> cur_freq(26, 0);
        for (int i = l; i < r; i++) {
            cur_freq[s2[i] - 'a']++;
        }

        while (r < s2.size()) {
            cur_freq[s2[r] - 'a']++;
            if (cur_freq == freq) return true;
            else {
                cur_freq[s2[l] - 'a']--;
                l++;
                r++;
            }
        }

        return false;
    }
};
