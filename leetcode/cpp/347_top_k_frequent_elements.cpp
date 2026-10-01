using std::unordered_map;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        vector<vector<int>> arr(nums.size()+1);

        for (auto const& x : freq) {
            arr[x.second].push_back(x.first);
        }
        vector<int> result;
        for (int i = nums.size(); i >=0 && k > 0; i--) {
            for (int n : arr[i]) {
                result.push_back(n);
                k--;
                if (k == 0) return result;
            }
        }
        return result;
    }
};
