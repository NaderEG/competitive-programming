class Solution {
public:
    string largestGoodInteger(string num) {
        int res = -1;
        for(int i = 0; i < num.length()-2; i++) {
            if(num[i] == num[i+1] && num[i+1] == num[i+2]) {
                int curr = (num[i] - '0')*100 + (num[i+1] - '0')*10 + (num[i+2] - '0');
                res = max(curr, res);
            }
        }
        if(res == -1) {
            return "";
        }
        if(res == 0) {
            return "000";
        }
        return to_string(res); 
    }
};