class Solution {
public:
    int findLucky(vector<int>& arr) {
        vector<int> freqs(500, 0);
        for(int num : arr) {
            freqs[num-1]++;
        }
        for(int i = 499; i >= 0; i--) {
            if(freqs[i] == i+1) {
                return i+1;
            }
        }
        return -1;
    }
};