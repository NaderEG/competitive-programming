using std::unordered_map;
using std::set;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int left[nums.size()];
        int i;
        for (i = 0; i < nums.size(); i++) {
            if (i == 0) {
                left[i] = 1;
            } else {
                left[i] = left[i-1] * nums[i-1];
            }
        }
        int right[nums.size()];
        for (i = nums.size()-1; i >= 0; i--) {
            if (i == nums.size()-1) {
                right[i] = 1;
            } else {
                right[i] = right[i+1] * nums[i+1];
            }
        }
        vector<int> result;
        for (i = 0; i < nums.size(); i++) {
            result.push_back(left[i] * right[i]);
        }
        return result;
    }
};
