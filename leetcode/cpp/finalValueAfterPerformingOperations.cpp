class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        unordered_map<string, int> ops = {
            {"++X", 1}, {"X++", 1}, {"--X", -1}, {"X--", -1}
        };
        int res = 0;
        for(string op : operations) {
            res = res + ops[op];
        }
        return res;
    }
};