class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> res;
        unordered_map<int, int> freqs;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == key) {
                for(int j = i-k; j < i + k + 1; j++) {
                    if(!freqs[j] && j  >= 0 && j < nums.size()) {
                        res.push_back(j);
                        freqs[j]++;
                    } 
                }
            }
        }
        return res;
    }
};