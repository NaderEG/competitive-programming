class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int res = 0;
        int local_min = nums[0];
        
        for(int i = 0; i < nums.size()-1; i++) {
            if(nums[i+1] - local_min > k) {
                res++;
                local_min = nums[i+1];
            }
        }
        return res+1;
    }
};