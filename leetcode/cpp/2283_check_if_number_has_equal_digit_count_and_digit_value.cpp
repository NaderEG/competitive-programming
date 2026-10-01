class Solution {
public:
    bool digitCount(string num) {
        unordered_map<char, int> freqs;
        for(char digit : num) {
            freqs[digit-'0']++;
        }

        for(int i = 0; i < num.size(); i++) {
            if(freqs[i] != num[i] - '0') {
                return false;
            }
        }
        return true;
    }
};