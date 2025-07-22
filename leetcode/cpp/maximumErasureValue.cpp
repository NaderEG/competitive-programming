class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> unique;
        int l = 0, r = 1;
        unique.insert(nums[0]);
        int sum = nums[0];
        int res = nums[0];

        while(r < nums.size()) {
            while(unique.count(nums[r])) {
                unique.erase(nums[l]);
                sum-= nums[l];
                l++;
            } 

            unique.insert(nums[r]);
            sum += nums[r];
            r++;
            
            res = max(sum, res);
            
        }
        return res;
    }
};