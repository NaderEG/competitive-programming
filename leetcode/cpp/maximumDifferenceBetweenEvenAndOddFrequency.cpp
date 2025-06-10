class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char, int> freqs;
        for(char letter : s) {
            freqs[letter]++;
        }

        int min_even = INT_MAX;
        int max_odd = INT_MIN;

        for (const auto& [ch, count] : freqs) {
            if (count % 2) {
                max_odd = max(max_odd, count);
            } else {
                min_even = min(min_even, count);
            }
        }
        return max_odd - min_even;
    }
};