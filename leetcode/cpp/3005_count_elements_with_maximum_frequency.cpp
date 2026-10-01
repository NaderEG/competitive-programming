class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int, int> freqs;
        for(int i = 0; i < nums.size(); i++) {
            freqs[nums[i]]++;
        }
        int max_val = 0;
        for(map<int, int>::iterator itr = freqs.begin(); itr != freqs.end(); ++itr) {
            max_val = max(max_val, itr->second);
        }
        int res = 0;
        for(map<int, int>::iterator itr = freqs.begin(); itr != freqs.end(); ++itr) {
            if(itr->second == max_val) {
                res+=max_val;
            }
        }
        return res;
    }
};