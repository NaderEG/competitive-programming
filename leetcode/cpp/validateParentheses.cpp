class Solution {
public:
    bool isValid(string s) {
        vector<char> stack;
        if (s.length() < 2) {
            return false;
        }
        for (char c : s) {
            if ((c == ')' || c == ']' || c == '}') && stack.size() == 0) {
                return false;
            }
            if (c == ')') {
                if ('(' != stack.back()) {
                    return false;
                }
                stack.pop_back();
            }
            else if (c == '}') {
                if ('{' != stack.back()) {
                    return false;
                }
                stack.pop_back();
            }
            else if (c == ']') {
                if ('[' != stack.back()) {
                    return false;
                }
                stack.pop_back();
            }
            else {
                stack.push_back(c);
            }
        }
        return stack.size() == 0;
    }
};
