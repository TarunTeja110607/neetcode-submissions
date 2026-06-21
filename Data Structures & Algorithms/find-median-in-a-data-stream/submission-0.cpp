class MedianFinder {
private:
    priority_queue<int> left; // max heap
    priority_queue<int, vector<int>, greater<int>> right; // min heap

public:
    MedianFinder() {
    }

    void addNum(int num) {
        left.push(num);

        // Ensure all elements in left <= all elements in right
        if (!right.empty() && left.top() > right.top()) {
            right.push(left.top());
            left.pop();
        }

        // Balance sizes
        if (left.size() > right.size() + 1) {
            right.push(left.top());
            left.pop();
        }

        if (right.size() > left.size() + 1) {
            left.push(right.top());
            right.pop();
        }
    }

    double findMedian() {
        if (left.size() > right.size()) {
            return left.top();
        }

        if (right.size() > left.size()) {
            return right.top();
        }

        return (left.top() + right.top()) / 2.0;
    }
};