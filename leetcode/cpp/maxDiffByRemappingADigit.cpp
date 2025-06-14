class Solution {
public:
    int minMaxDifference(int num) {
        string s_num = to_string(num);
        char min_replace = '0';
        char max_replace = '9';
        for(char letter : s_num) {
            if(letter != '9' && max_replace == '9') {
                max_replace = letter;
            }
            if(letter != '0' && min_replace == '0') {
                min_replace = letter;
            }
            
        }
        string max_num = s_num;
        string min_num = s_num;
        for(int i = 0; i < s_num.length(); i++) {
            if(s_num[i] == max_replace) {
                max_num[i] = '9';
            }
            if(s_num[i] == min_replace) {
                min_num[i] = '0';
            }
        }
        return stoi(max_num) - stoi(min_num);

    }
};