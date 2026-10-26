class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> output;
        unordered_map<int, int> m;

        for (int i : nums) m[i]++;

        set<vector<int>> seen;

        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                int complement = -(nums[i]+nums[j]);
                int needed = 1 + (nums[i] == complement) + (nums[j] == complement);
                // above checks if there are the necessary amounts of elements to construct a valid triplet
                auto it = m.find(complement); // iterator to the key value pair

                if (it != m.end() && it->second >= needed) {
                    vector<int> element = {nums[i], nums[j], complement};
                    sort(element.begin(), element.end());
                    if (seen.insert(element).second) {
                        // if we are inserting into seen for the first time
                        output.push_back(element);
                    }
                }
            }
        }
        return output;
    }
};
