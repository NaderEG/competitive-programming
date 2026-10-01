class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words;
        vector<bool> dp(s.length()+1);
        for(string word : wordDict) {
            words.insert(word);
        }
        dp[s.length()] = true;
        for (int j = s.length()-1; j >= 0; j--) {
            // words.contains(getSubstring(s, j, s.length()))
            for(string w : wordDict) {
                if(j+w.length() <= s.length() && words.count(s.substr(j, w.length())) > 0) {
                    dp[j] = dp[j] || dp[j+w.length()];
                }
            }
        }
        return dp[0];
    }
};
