class FindSumPairs {
public:
vector<int> vec1, vec2;
unordered_map<int, int> freqs;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        vec1 = nums1;
        vec2 = nums2;
        for(int num : nums2) {
            freqs[num]++;
        }
    }
    
    void add(int index, int val) {
        freqs[vec2[index]]--;
        vec2[index] += val;
        freqs[vec2[index]]++;
    }
    
    int count(int tot) {
        int c = 0;
        for(int i = 0; i < vec1.size(); i ++) {
            if(freqs.count(tot-vec1[i])) {
                c+=freqs[tot-vec1[i]];
            }
        }
        return c;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */