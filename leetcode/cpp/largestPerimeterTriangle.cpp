class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        // want to find the three largest a, b, c such that
        // a + b < c
        // a + c < b
        // b + c < a

        sort(nums.rbegin(), nums.rend());
        int max_peri = 0;
        for(int a = 0; a < nums.size()-2; a++) {
            int b = a + 1;
            int c = a + 2;
            if(nums[a] + nums[b] > nums[c] && nums[a] + nums[c] > nums[b] && nums[b] + nums[c] > nums[a]) {
                max_peri = max(max_peri, nums[a] + nums[b] + nums[c]);
            }
        }
        return max_peri;
    }
};