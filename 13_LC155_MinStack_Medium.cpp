#include <stack>

class MinStack {
private:
    std::stack<int> st;
    std::stack<int> minSt;

public:
    MinStack() = default;

    void push(int val) {
        st.push(val);

        if (minSt.empty() || val <= minSt.top()) {
            minSt.push(val);
        }
    }

    void pop() {
        if (!st.empty() && !minSt.empty() && st.top() == minSt.top()) {
            minSt.pop();
        }

        if (!st.empty()) {
            st.pop();
        }
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return minSt.top();
    }
};
