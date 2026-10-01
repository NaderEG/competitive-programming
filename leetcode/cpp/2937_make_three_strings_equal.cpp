class Solution {
public:
    int findMinimumOperations(string s1, string s2, string s3) {
        int min_len = min({s1.length(), s2.length(), s3.length()});
        int prefix_len = 0;
        for(int i = 0; i < min_len; i++) {
            if(s1[i] == s2[i] && s2[i] == s3[i]) {
                prefix_len++;
            } else {
                break;
            }
        }
        if(prefix_len == 0) {
            return -1;
        }
        return s1.length() - prefix_len + s2.length() - prefix_len + s3.length() - prefix_len;
    }
};