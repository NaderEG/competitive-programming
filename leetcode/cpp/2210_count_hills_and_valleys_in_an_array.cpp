class Solution {
public:
    int countHillValley(vector<int>& nums) {
        vector<int> map;
        for(int i = 0; i < nums.size()-1; i++) {
            if(nums[i] != nums[i+1]) {
                map.push_back(nums[i]);
            }
        }
        if(map.size() == 0) {
            return 0;
        }
        if(map.back() != nums.back()) {
            map.push_back(nums.back());
        }
        int res = 0;
        
        for(int i = 1; i < map.size()-1; i++) {
            if(map[i-1] < map[i] && map[i+1] < map[i]) {
                res++;
            }
            if(map[i-1] > map[i] && map[i+1] > map[i]) {
                res++;
            }
        }
        return res;
    }
};