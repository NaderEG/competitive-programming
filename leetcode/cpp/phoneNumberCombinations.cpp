class Solution {
public:
    vector<string> result;

    map<char, vector<string>> keys = {
        {'2', {"a", "b", "c"}},
        {'3', {"d", "e", "f"}},
        {'4', {"g", "h", "i"}},
        {'5', {"j", "k", "l"}},
        {'6', {"m", "n", "o"}},
        {'7', {"p", "q", "r", "s"}},
        {'8', {"t", "u", "v"}},
        {'9', {"w", "x", "y", "z"}}
    };

    void combs_helper(string acc, int i, string digits) {
        if(i >= digits.length()) {
            result.push_back(acc);
        }
        for(string c : keys[digits[i]]) {
            combs_helper(acc + c, i+1, digits);
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0) {
            return vector<string>();
        }
        combs_helper("", 0, digits);
        return result;
    }
};
