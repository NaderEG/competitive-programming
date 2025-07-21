class Solution {
public:
    string makeFancyString(string s) {
        int num_consecutive = 1;
        string res = "";
        res += s[0];
        for(int i = 1; i < s.length(); i++) {
            if(res[res.length()-1] == s[i] && num_consecutive < 2) {
                res += s[i];
                num_consecutive++;
            } else if(res[res.length()-1] != s[i]) {
                res+= s[i];
                num_consecutive = 1;
            } 
        }
        return res;

    }
};