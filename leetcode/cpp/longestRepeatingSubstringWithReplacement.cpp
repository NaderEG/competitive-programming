class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, r = 0;
        unordered_map<char, int> letters;
        int res = 0, max_freq = 0;

        while (r < s.size()) {
            letters[s[r]]++;
            max_freq = max(max_freq, letters[s[r]]);
            int win_len = r - l + 1;

            if (win_len - max_freq > k) {
                letters[s[l]]--;
                l++;
            }
            
            res = max(res, r - l + 1);
            r++;
        }
        return res;
    }
};