using std::unordered_set;
using std::unordered_map;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        // Make a first pass to construct a frequency map of the nums
        unordered_set<int> freqs;
        for (int num : nums) {
            freqs.insert(num);
        }
        unordered_map<int, int> sequences;
        // Make a pass of the map in order to find sequence starters
        int next;
        for (int n : freqs) {
            //container.find(element) != container.end()
            if (freqs.find(n-1) != freqs.end()) {
                next = n+1;
                sequences[n] = 1;
                while(freqs.find(next) != freqs.end()) {
                    sequences[n]++;
                    next++;
                }
            }
        }
        int max = 0;
        for (auto const& [k, v] : sequences) {
            if (v > max) {
                max = v;
            }
        }
        return max+1;


    }
};
