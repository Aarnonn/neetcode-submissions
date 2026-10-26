class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int r = numbers.size()-1;

        while (l < r) {
            int left = numbers[l], right = numbers[r];
            if (left + right == target) return {l+1, r+1};
            else if (left + right < target) {
                l += 1;
            }
            else if (left + right > target) {
                r -= 1;
            }
        }

        return {0, 0};
    }
};
