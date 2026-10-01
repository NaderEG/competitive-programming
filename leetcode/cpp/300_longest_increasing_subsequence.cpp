class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> LIS_including(nums.size());
        int global_max = 0;
        for(int i = nums.size()-1; i >=0; i--) {
            int max = 0;
            for(int j = i; j < nums.size(); j++) {
                if(nums[j] > nums[i] && LIS_including[j] > max) {
                    max = LIS_including[j];
                }
            }
            LIS_including[i] = max+1;
            if (LIS_including[i] > global_max) {
                global_max = LIS_including[i];
            }
        }
        return global_max;
    }
};
