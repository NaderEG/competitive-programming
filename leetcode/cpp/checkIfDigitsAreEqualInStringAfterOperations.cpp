class Solution {
public:
    bool hasSameDigits(string s) {
        while(s.length() > 2) {
            string new_s = "";
            for(int i = 0; i < s.length()-1; i++) {
                int num = (charToInt(s[i]) + charToInt(s[i+1])) % 10;
                new_s+=to_string(num);
            }
            s = new_s;
        }
        return s[0] == s[1];
            
    }

    int charToInt(char c) {
        return c-'0';
    }
};