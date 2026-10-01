#include <climits>

class MinStack {
public:
    vector<int> minStack;
    vector<int> stack;
    MinStack() {
        
    }
    
    void push(int val) {
        if (minStack.empty() || val <= minStack.back()){
            minStack.push_back(val);
        }
        stack.push_back(val);
    }
    
    void pop() {
        if (stack.back() == minStack.back()) {
            minStack.pop_back();
        }
        stack.pop_back();
    }
    
    int top() {
        return stack[stack.size()-1];
    }
    
    int getMin() {
        return minStack.back();
    }
};
