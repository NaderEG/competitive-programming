class MedianFinder {
private: 
    priority_queue<int, vector<int>, greater<int>> top_half;
    priority_queue<int> bottom_half;
public:
    MedianFinder() {}
    
    void addNum(int num) {
        if(top_half.empty() || num >= findMedian()) {
            top_half.push(num);
        } else {
            bottom_half.push(num);
        }

        if(top_half.size() > bottom_half.size() + 1) {
            bottom_half.push(top_half.top());
            top_half.pop();
        } else if(bottom_half.size() > top_half.size() + 1) {
            top_half.push(bottom_half.top());
            bottom_half.pop();
        }

    }
    
    double findMedian() {
        if(bottom_half.size() == top_half.size()) {
            return (bottom_half.top() + top_half.top()) / 2.0;
        } else if (bottom_half.size() > top_half.size()) {
            return bottom_half.top();
        } else {
            return top_half.top();
        }
    }
};
