class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0) {
            return false;
        }
        priority_queue<int, vector<int>, greater<int>> minHeap;
        unordered_map<int, int> freqs;
        for(int num : hand) {
            freqs[num]++;
        }
        for(const auto& kv : freqs) {
            minHeap.push(kv.first);
        }
        while(minHeap.size()) {
            while(minHeap.size() && freqs[minHeap.top()] == 0) {
                minHeap.pop();
            }
            if(minHeap.empty()) break;
            int min = minHeap.top();
            for(int i = min; i < min+groupSize; i++) {
                if(!freqs[i]) {
                    return false;
                }
                freqs[i]--;
            }
        }
        return true;
    }
};
