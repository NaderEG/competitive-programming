class Solution {
public:
    int maxPower(string s) {
        int max_power = 0;
        if(s.length() == 0) {
            return 0;
        }
        if(s.length() == 1) {
            return 1;
        }
        int i = 0;
        while(i < s.length()-1) {
            int curr_power = 1;
            while(s[i] == s[i+1]) {
                curr_power++;
                i++;
            }
            if(curr_power > max_power) {
                max_power = curr_power;
            }
            i++;
        }
        return max_power;
    }
};