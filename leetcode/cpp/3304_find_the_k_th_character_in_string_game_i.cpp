class Solution {
public:
    string transform_string(string current) {
        string app = "";
        for(char letter : current) {
            app += (letter + 1 - 97) % 26 + 97;
        }
        return current + app;
    }

    char kthCharacter(int k) {
        string res = "a";
        while(res.length() < k) {
            res = transform_string(res);
        }
        return res[k-1];
    }
};