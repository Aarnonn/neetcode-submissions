class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for (auto i : tokens) {
            if (i != "+" && i != "-" && i != "*" && i != "/") {
                s.push(stoi(i));
            }
            else {
                int n1 = s.top();
                s.pop();
                int n2 = s.top();
                s.pop();
                if (i == "+") {
                    s.push(n1 + n2);
                }
                else if (i == "-") {
                    s.push(n2 - n1);
                }
                else if (i == "*") {
                    s.push(n1 * n2);
                }
                else if (i == "/") {
                    s.push(n2 / n1);
                }
            }
        }
        return s.top();
    }
};
