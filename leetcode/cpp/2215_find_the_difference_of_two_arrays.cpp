class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        set<int> in_list_1;
        set<int> in_list_2;

        for(int num : nums1) {
            in_list_1.insert(num);
        }

        for(int num : nums2) {
            in_list_2.insert(num);
        }

        vector<vector<int>> res = {{}, {}};

        for(int num : in_list_1) {
            if(!in_list_2.contains(num)) {
                res[0].push_back(num);
            }
        }

        for(int num : in_list_2) {
            if(!in_list_1.contains(num)) {
                res[1].push_back(num);
            }
        }
        return res;
    }
};