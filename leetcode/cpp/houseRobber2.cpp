class Solution {
public:
    int rob_helper(vector<int>& nums) {

        int start = nums[0];
        int second = start < nums[1] ? nums[1] : start;
        vector<int> result {start, second};
        for(int i = 2; i < nums.size(); i++) {
            result.push_back(max(nums[i]+result[i-2], result[i-1]));
        }
        return result.back();
    }

    int rob(vector<int>& nums) {
        if(nums.size() == 0) {
            return 0;
        } else if(nums.size() == 1) {
            return nums[0];
        } else if (nums.size() <= 2) {
            return max(nums[0], nums[1]);
        }
        vector<int> first_to_penultimate(nums.begin(), nums.end()-1);
        vector<int> second_to_last(nums.begin()+1, nums.end());
        
        

        return max(rob_helper(first_to_penultimate), rob_helper(second_to_last));
    }
};
