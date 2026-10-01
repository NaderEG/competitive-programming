class Solution {
public:
    int jump(vector<int>& nums) {
        int l = 0, r = 0;
        int count = 0;
        while(r < nums.size()-1) {
            int curr_max_dist = 0;
            for(int i = l; i <= r; i++) {
                curr_max_dist = max(curr_max_dist, i + nums[i]);
            }

            l = r+1;
            r=curr_max_dist;
            count++;
            
        }
        return count;
    }
};
