class Solution {
public:
    int res = 0;
    string getSubstring(const std::string& input, size_t i, size_t j) {
        if (i > j || j > input.size()) {
            throw std::out_of_range("Invalid indices");
        }
        return input.substr(i, j - i+1);
    }

    void getOddPalindromeAt(int i, string s) {
        int left = i;
        int right = i;
        res++;
        while(true) {
            left--;
            right++;
            if(s[left] != s[right] || left < 0 || right >= s.size()) {
                return;
            }
            res++;    
        }
    }
    void getEvenPalindromeAt(int i, string s) {
        int left = i;
        int right = i+1;
        if(s[left] != s[right] || right == s.size()) {
            return;
        }
        res++;
        while(true) {
            left--;
            right++;
            if(s[left] != s[right] || left < 0 || right >= s.size()) {
                return;
            }
            res++;

            
                
        }
    }
    int countSubstrings(string s) {
        for(int i = 0; i < s.length(); i++) {
            getEvenPalindromeAt(i, s);
            getOddPalindromeAt(i, s);
        }
        return res;
    }
};
