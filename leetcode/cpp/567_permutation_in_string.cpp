class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) {
            return false;
        }
        vector<int> freqs(26, 0), ans(26, 0);

        for(char c : s1) {
            ans[c - 'a']++;
        }
        int left = 0;
        int right = 0;

        while(right < s1.length()) {
            freqs[s2[right]- 'a']++;
            right++;
        }
        right--;
        if(freqs == ans) {
            return true;
        }
        while (right < s2.length()) {
            freqs[s2[left] - 'a']--;
            left++;
            right++;
            if (right < s2.length()) {
                freqs[s2[right] - 'a']++;
            }
            if(freqs == ans) {
                return true;
            }
        }
        return false;

        
    }
};
