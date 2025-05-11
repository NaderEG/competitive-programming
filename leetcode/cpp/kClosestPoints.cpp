class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        struct Compare {
            bool operator()(vector<int> a, vector<int> b) {
                return sqrt((a[0])*(a[0]) + (a[1])*(a[1])) < sqrt((b[0])*(b[0]) + (b[1])*(b[1]));
            }
        };
        priority_queue<vector<int>, vector<vector<int>>, Compare> heap;

        for(vector<int> point : points) {
            if(heap.size() >= k) {
                heap.push(point);
                heap.pop();
            } else {
                heap.push(point);
            }
        }
        vector<vector<int>> result;
        while(!heap.empty()) {
            result.push_back(heap.top());
            heap.pop();
        }
        return result;

    }
};
