class Solution {
public:
    int possibleStringCount(string word) {
        int count = 1;
        vector<int> occurences;
        for(int i = 1; i < word.length(); i++) {
            if(word[i] == word[i-1]) {
                ++count;
            } else {
                occurences.push_back(count);
                count = 1;
            }
        }
        occurences.push_back(count);
        int res = 1;
        for(int num : occurences) {
            res+=num-1;
        }
        return res;
    }
};