class Solution {
public:
    bool checkValidString(string s) {
        int min_open = 0;
        int max_open = 0;
        for(char c : s) {
            if(c == '(') {
                min_open++;
                max_open++;
            } else if(c == ')') {
                if(min_open > 0) min_open--;
                max_open--;
            } else {
                max_open++;
                if(min_open > 0) min_open--;
            }

            if(max_open < 0) {
                return false;
            }
        }
        return min_open == 0;
    }
};
