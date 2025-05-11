class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.length()-1;

        while (i < j) {
            if(!isalnum(s[i])) {
                i++;
            } else if(!isalnum(s[j])) {
                j--;
            } else {
                if (tolower(s[i]) != tolower(s[j]) ) {
                    return false;
                }
                i++;
                j--;
            }
        }
        return true;
    }
    string getSubstring(const string& input, size_t i, size_t j) {
        if (i > j || j > input.size()) {
            throw std::out_of_range("Invalid indices");
        }
        return input.substr(i, j - i);
    }
    vector<vector<string>> result;
    void partition_helper(string s, int i, vector<string> acc) {
        if (i >= s.length()) {
            result.push_back(acc);
            return;
        }
        for (int j = i; j < s.length(); j++) {
            if(isPalindrome(getSubstring(s, i, j+1))) {
                acc.push_back(getSubstring(s, i, j+1));
                partition_helper(s, j+1, acc);
                acc.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        partition_helper(s, 0, vector<string>());
        return result;
    }
};
