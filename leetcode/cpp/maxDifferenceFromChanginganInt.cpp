class Solution {
public:
    int maxDiff(int num) {
        string s_num = to_string(num);
        char min_replace = '0';
        char max_replace = '9';
        for(char letter : s_num) {
            if(letter != '9' && max_replace == '9') {
                max_replace = letter;
            }            
        }

        // horrible naming convention but ironically I find this more readable I would never do this in production code

        char replace_this_char = '1';
        char with_this_char = '1';
        if(s_num[0] != '1') {
            replace_this_char = s_num[0];
            with_this_char = '1';
        } else {
            for(char letter : s_num) {
                if(letter != '1' && letter != '0') {
                    replace_this_char = letter;
                    with_this_char = '0';
                    break;
                }
            }
        }

        string max_num = s_num;
        string min_num = s_num;
        for(int i = 0; i < s_num.length(); i++) {
            if(s_num[i] == max_replace) {
                max_num[i] = '9';
            }
            if(s_num[i] == replace_this_char) {
                min_num[i] = with_this_char;
            }
        }
        return stoi(max_num) - stoi(min_num);
    }
};