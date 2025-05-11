using std::unordered_map;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() <= 0) {
            return 0;
        }
        int l = 0;
        int r = 0;

        unordered_set<char> set;
        set.insert(s[l]);
        int max = (r - l) + 1;
        while(r < s.size()) {
            if(r - l + 1 > max) {
                max = r - l + 1;
            }
            if (!set.count(s[r+1])) {
                set.insert(s[r+1]);
                r++;
            } else {
                set.erase(s[l]);
                l++;
            }
        }
        return max;
    }
};
