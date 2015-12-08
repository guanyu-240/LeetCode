class MedianFinder {
private:
    priority_queue<int, vector<int>, less<int>> lower;
    priority_queue<int, vector<int>, greater<int>> higher;
public:
    MedianFinder () {
        lower.push(INT_MIN);
        higher.push(INT_MAX);
    }
    // Adds a number into the data structure.
    void addNum(int num) {
        if (lower.top() > num) {
            lower.push(num);
            if (lower.size() - higher.size() == 2) {
                higher.push(lower.top());
                lower.pop();
            }
        }
        else {
            higher.push(num);
            if (higher.size() - lower.size() == 2) {
                lower.push(higher.top());
                higher.pop();
            }
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        if (lower.size() > higher.size()) return (double)lower.top();
        else if (higher.size() > lower.size()) return (double)higher.top();
        else return ((double)lower.top() + (double)higher.top())/2;
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();
