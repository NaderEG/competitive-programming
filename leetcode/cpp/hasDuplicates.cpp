#include <unordered_set>

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> uset;

        for (auto x : nums) {
            if (uset.count(x) > 0) {
                return true;
            } else {
                uset.insert(x);
            }
        }
        return false;
    }
};
