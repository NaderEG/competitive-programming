class Solution {
public:
    int minimumDeletions(string word, int k) {
        map<char, int> freqs;
        for(char letter : word) {
            freqs[letter]++;
        }
        int min_delete = word.length();

        for(const auto& [key_i, value_i]  : freqs) {
            int local_min = 0;
            for(const auto& [key_j, value_j] : freqs) {
                if(value_j < value_i) {
                    local_min += value_j;
                } else {
                    local_min += max(value_j - value_i - k, 0);
                }
            }
            min_delete = min(local_min, min_delete);
        }
        return min_delete;
    }
};