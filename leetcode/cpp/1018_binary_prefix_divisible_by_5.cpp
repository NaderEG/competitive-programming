class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> res;
        int sum = 0;
        for(int digit : nums) {
            sum = (sum*2 + digit) % 5;
            res.push_back(sum % 5 == 0);
            
        }
        return res;
    }
};