class MinStack {
private:
    stack<int> main;
    stack<int> mins;
public:
    MinStack() {}
    
    void push(int val) {
        int minVal = main.empty() ? val : min(val, mins.top());
        main.push(val);
        mins.push(minVal);
    }
    
    void pop() {
        main.pop();
        mins.pop();
    }
    
    int top() {
        return main.top();
    }
    
    int getMin() {
        return mins.top();
    }
};
