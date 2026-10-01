class Solution {
public:
    int maxSum(vector<int>& nums) {
        int max_num = nums[0];
        for(int i = 0; i < nums.size(); i++) {
            max_num = max(max_num, nums[i]);
        }
        if(max_num <= 0) {
            return max_num;
        }
        set<int> unique_nums;
        for(int num : nums){
            if(num > 0) {
                unique_nums.insert(num);
            }
        }
        int sum = accumulate(unique_nums.begin(), unique_nums.end(), 0);
        return sum;
    }
};