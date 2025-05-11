class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> heap;
        for(int num : nums) {
            if(heap.size() >= k) {
                heap.push(num);
                heap.pop();
            }
            else {
                heap.push(num);
            }
        }
        
        return heap.top();
    }
};
