class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 1) {
            return nums[0];
        }
        int global_max = nums[0];

        int currmax = 1;
        int currmin = 1;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0) {
                currmin = 1;
                currmax = 1;
                if(0 > global_max) {
                    global_max = 0;
                }
                continue;
            }
            int tmp = currmax;
            currmax = max(nums[i], max(currmax*nums[i], currmin*nums[i]));
            currmin = min(nums[i], min(nums[i]*tmp, currmin*nums[i]));
            global_max = max(currmax, global_max);

        }
        return global_max;

    }
};
