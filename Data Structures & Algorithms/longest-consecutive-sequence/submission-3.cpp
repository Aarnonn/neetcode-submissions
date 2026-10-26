class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        
        unordered_map<int, int> m;

        for (const auto& i : nums) {
            if (m.contains(i)) continue;
            m[i] = i + 1;
        }

        int longest = 1;
        int cur = 1;

        for (const auto& p : m) {
            if (m.contains(p.first-1)) continue; // CRITICAL for keeping this time efficient. Make sure you don't walk from each element. Otherwise we are doing an O(n^2) solution even with the right intuititon.
            int key = p.first;
            while (m.contains(m[key])) {
                cur++;
                if (cur > longest) longest = cur;
                key = m[key];
            }
            cur = 1;
        }

        return longest;
    }
};
