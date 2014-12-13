class MinStack {
public:
    /*
    Keep the top element of minSt as the min element in the main stack
    */
    stack<int> mainSt;
    stack<int> minSt;
    void push(int x) {
        mainSt.push(x);
        if (minSt.empty() || minSt.top() >= x) minSt.push(x);
    }

    void pop() {
        if (mainSt.empty()) return;
        if (!minSt.empty() && minSt.top() == mainSt.top()) minSt.pop();
        mainSt.pop();
    }

    int top() {
        return mainSt.top();
    }

    int getMin() {
        return minSt.top();
    }
};
