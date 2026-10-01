class Solution {
public:
    bool isValid(string s) {
        vector<char> stack;
        for(char c : s) {
            if(c == '(' || c == '{' || c == '[') {
                stack.push_back(c);
            } else {
                if(stack.empty()) {
                    return false;
                }
                char d = stack.back();
                stack.pop_back();

                if(d == '(' && c != ')' || d == '{' && c != '}' || d == '[' && c != ']') {
                    return false;
                }
            }
        }
        return true && stack.empty();
    }
};