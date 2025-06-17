class Solution {
public:
    string minWindow(string s, string t) {
        string res = "";
        int res_length = INT_MAX;
        int r = 0;
        int l = 0;
        int have = 0;
        unordered_map<char, int> target;
        for(char letter : t) {
            target[letter]++;
        }
        int want = target.size();

        unordered_map<char, int> search;
        while(r <= s.length()) {
            if(have < want) {
                r++;
                if(target[s[r-1]] > 0) {
                    search[s[r-1]]++;
                    if(search[s[r-1]] == target[s[r-1]]) have++;
                }
            } else {
                l++;
                if(target[s[l-1]] > 0) {
                    search[s[l-1]]--;
                    if(search[s[l-1]] < target[s[l-1]]) have--;
                }
            }
            if(have == want && r-l < res_length) {
                res = s.substr(l, r-l);
                res_length = r-l;
            }
        }
        return res;
    }
};
