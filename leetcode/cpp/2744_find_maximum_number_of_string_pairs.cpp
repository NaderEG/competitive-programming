class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        int res = 0;
        for(int i = 0; i < words.size(); i++) {
            for(int j = i+1; j < words.size(); j++) {
                if(words[i] == string(words[j].rbegin(), words[j].rend())) {
                    res++;
                    break;
                }
            }
        }
        return res;
    }
};