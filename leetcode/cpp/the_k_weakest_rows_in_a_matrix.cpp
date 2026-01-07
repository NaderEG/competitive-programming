class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> sums;
        for(int i = 0; i < mat.size(); i++) {
            int curr_sum = 0;
            for(int j = 0; j < mat[i].size(); j++) {
                curr_sum += mat[i][j];
            }
            sums.push_back(curr_sum);
        }
        priority_queue<pair<int,int>> heap;

        for (int i = 0; i < sums.size(); i++) {
            heap.push({sums[i], i});
            if (heap.size() > k) {
                heap.pop();
            }
        }

        vector<int> res;
        while (!heap.empty()) {
            res.push_back(heap.top().second);
            heap.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};