class Solution {
public:
    vector<string> result;
    void helper_generate_parenthesis(string s, int n, int open, int close) {
        if(close == n) {
            result.push_back(s);
            return;
        }
        if(close < open) {
            helper_generate_parenthesis(s+")", n, open, close+1);
        }
        if(open < n) {
            helper_generate_parenthesis(s+"(", n, open+1, close);
        }
        
    }

    vector<string> generateParenthesis(int n) {
        helper_generate_parenthesis("(", n, 1, 0);
        return result;
    }
};
