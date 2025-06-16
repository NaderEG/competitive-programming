class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int res = -1;
        if(nums.size() < 2) return res;
        if(nums.size() == 2) {
            res = max(res, nums[1] - nums[0]);
            if(res == 0) {
                return -1;
            } else {
                return res;
            }
        }
        

        int l = 0;
        int r = 1;
        while(l < nums.size()-1) {
            if(r == nums.size()-1) {
                res = max(res, nums[r] - nums[l]);
                l++;
            }
            else {
                if(l == r) {
                    r++;
                } else if(nums[l] > nums[r]) {
                    l++;
                } else {
                    res = max(res, nums[r] - nums[l]);
                    r++;
                }
            }
            
        }
        if(res == 0) res = -1;
        return res;
    }
};