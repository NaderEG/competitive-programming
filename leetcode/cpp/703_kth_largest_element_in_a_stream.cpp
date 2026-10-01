class KthLargest {
public:
    int capacity;
    int size;
    priority_queue<int, vector<int>, greater<int>> heap;
    KthLargest(int k, vector<int>& nums) {
        size = 0;
        capacity = k;
        for(int num : nums) {
            add(num);
        }
    }
    
    int add(int val) {
        if(size < capacity) {
            heap.push(val);
            size++;
        } else {
            if (val > heap.top()) {
                heap.pop();
                heap.push(val);
            }
        }
        return heap.top();
    }
};
