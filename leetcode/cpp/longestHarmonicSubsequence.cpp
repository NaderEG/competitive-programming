class Solution {
public:
    int findLHS(vector<int>& nums) {
        int res = 0;
        unordered_map<int, int> freqs;
        for(int num : nums) {
            freqs[num]++;
        }
        for(auto& it : freqs) {
            if(freqs.count(it.first+1)) {
                res = max(freqs[it.first] + freqs[it.first+1], res);
            }
        }
        return res;
    }
};