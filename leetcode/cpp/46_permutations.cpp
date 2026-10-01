class Solution {
public:
    vector<vector<int>> result;

    void permute_helper(vector<int> nums, vector<bool> used, vector<int> acc) {
        if(acc.size() == nums.size()) {
            result.push_back(acc);
        }
        for(int i = 0; i < used.size(); i++) {
            if(!used[i]) {
                used[i] = true;
                acc.push_back(nums[i]);
                permute_helper(nums, used, acc);
                used[i] = false;
                acc.pop_back();
            }
        }   
    }

    vector<vector<int>> permute(vector<int>& nums) {
        
        permute_helper(nums, vector<bool>(nums.size(), false), vector<int>());
        return result;
    }
};
