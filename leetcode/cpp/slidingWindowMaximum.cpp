class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        unordered_map<int, int> freqs;
        priority_queue<int> heap;
        vector<int> res;
        int right = 0, left = 0;
        while(right-left < k) {
            if(freqs[nums[right]] == 0) {
                heap.push(nums[right]);
            }
            freqs[nums[right]]++;
            right++;
        }
        res.push_back(heap.top());
        while(right < nums.size()) {
            if(freqs[nums[right]] == 0) {
                heap.push(nums[right]);
            }
            freqs[nums[right]]++;
            right++;
            freqs[nums[left]]--;
            left++;
            while(!heap.empty() && freqs[heap.top()] == 0) {
                heap.pop();
            }
            res.push_back(heap.top());
        }
        return res;
        
    }
};