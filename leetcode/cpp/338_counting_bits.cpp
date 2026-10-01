class Solution {
public:
    vector<int> countBits(int n) {
        if(n == 0) {
            return {0};
        }
        if(n == 1) {
            return {0, 1};
        }
        vector<int> res = {0, 1};
        int current_size = res.size();
        while(res.size() <= n) {
            current_size = res.size();
            for(int i = 0; i < current_size; i++) {
                res.push_back(1+res[i]);
                if(res.size() > n) {
                    break;
                }
            }
        }
        return res;
    }
};
