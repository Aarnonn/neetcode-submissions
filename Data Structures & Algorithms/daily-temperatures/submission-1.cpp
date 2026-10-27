class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> s;
        s.push({temperatures[0], 0});
        // stack of days where we are still waiting for there to be a warmer temperature. includes their index
        vector<int> result(temperatures.size());
        for (int i = 1; i < temperatures.size(); i++) {
            while (!s.empty() && temperatures[i] > s.top().first) {
                result[s.top().second] = i - s.top().second;
                s.pop();
            }
            s.push({temperatures[i], i});
        }

        return result;
    }
};
