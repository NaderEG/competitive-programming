class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> heap;
        for (int stone : stones) {
            heap.push(stone);
        }
        while (heap.size() > 1) {
            int stone1 = heap.top();
            heap.pop();
            int stone2 = heap.top();
            heap.pop();

            int new_stone = abs(stone1 - stone2);
            if (new_stone > 0) {
                heap.push(new_stone);
            } 
        }
        if (!heap.empty()) {
            return heap.top();
        }
        return 0;
    }
};
