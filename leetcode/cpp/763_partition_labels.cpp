class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> result;
        unordered_map<char, int> freqs;
        for(char letter : s) {
            freqs[letter]++;
        }
        set<char> curr_proc;
        int count = 0;
        for(char letter : s) {
            curr_proc.insert(letter);
            count++;
            freqs[letter]--;
            if(!freqs[letter]) {
                curr_proc.erase(letter);
            }
            if(!curr_proc.size()) {
                result.push_back(count);
                count = 0;
            }
        }
        return result;
    }
};
