class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        vector<int> freq(26, 0);
        int l = 0, n = s1.size(), r = l+n-1;
        for (char c : s1) {
            freq[c - 'a']++;
        }
        for (auto i : freq) {
            cout << i << " ";
        }
        cout << "\n";
        while (r < s2.size()) {
            vector<int> cur_freq(26, 0);
            for (int i = l; i <= r; i++) {
                cur_freq[s2[i] - 'a']++;
            }
            cout << "cur: ";
            for (auto i : cur_freq) {
                cout << i << " ";
            }
            cout << "\n";
            if (cur_freq == freq) return true;
            else {
                l++;
                r++;
            }
        }

        return false;
    }
};
