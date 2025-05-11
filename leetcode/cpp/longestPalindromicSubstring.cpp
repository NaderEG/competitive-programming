class Solution {
public:

    string getSubstring(const std::string& input, size_t i, size_t j) {
        if (i > j || j > input.size()) {
            throw std::out_of_range("Invalid indices");
        }
        return input.substr(i, j - i+1);
    }

    string longestOddPalindromeAt(int i, string s) {
        int left = i;
        int right = i;
        string res = getSubstring(s, left, right);
        while(true) {
            left--;
            right++;
            if(s[left] != s[right] || left < 0 || right >= s.size()) {
                return res;
            }
            res = getSubstring(s, left, right);      
        }
    }
    string longestEvenPalindromeAt(int i, string s) {
        int left = i;
        int right = i+1;
        if(s[left] != s[right] || right == s.size()) {
            return "";
        }
        string res = getSubstring(s, left, right);
        
        while(true) {
            left--;
            right++;
            if(s[left] != s[right] || left < 0 || right >= s.size()) {
                return res;
            }
            res = getSubstring(s, left, right);

            
                
        }
    }

    string longestPalindrome(string s) {
        string result = "";
        for(int i = 0; i < s.length(); i++) {
            string longestEven = longestEvenPalindromeAt(i, s);
            result = longestEven.length() > result.length() ? longestEven : result;
            string longestOdd = longestOddPalindromeAt(i, s);
            result = longestOdd.length() > result.length() ? longestOdd : result;

        }
        return result;
    }
};
