class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> result;
        for(int i = 0; i < s.length(); i+=k) {
            string current_string = "";
            for(int j = i; j < i+k; j++) {
                if(j < s.length()) current_string+=s[j];
                else current_string+=fill;
            }
            result.push_back(current_string);
        }
        return result;
    }
};