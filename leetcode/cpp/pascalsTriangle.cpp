class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        result.push_back({1});
        for(int i = 1; i < numRows; i++) {
            vector<int> previous = result[i-1];
            vector<int> current;
            for(int j = 0; j <= previous.size(); j++) {
                if(j == 0 || j == previous.size()) {
                    current.push_back(1);
                } else {
                    current.push_back(previous[j-1] + previous[j]);
                }
            }
            result.push_back(current);
        }
        return result;
    }
};