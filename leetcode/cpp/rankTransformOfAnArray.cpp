class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> arr_copy = arr;
        sort(arr_copy.begin(), arr_copy.end());
        unordered_map<int, int> rank_map;
        int rank = 1;
        for(int num : arr_copy) {
            if(rank_map[num] == 0) {
                rank_map[num] = rank;
                rank++;
            }
        }
        vector<int> res;
        for(int num : arr) {
            res.push_back(rank_map[num]);
        }
        return res;
    }
};