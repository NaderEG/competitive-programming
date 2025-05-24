class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> frequencies;
        unordered_map<char, int> delays;
        for(char task : tasks) {
            delays[task] = 0;
            frequencies[task]++;
        }
        auto cmp = [&frequencies](const char& a, const char& b) {
            return frequencies[a] < frequencies[b];
        };

        priority_queue<char, vector<char>, function<bool(const char&, char&)>> heap(cmp);
        for(const auto& pair : frequencies) {
            heap.push(pair.first);
        }

        queue<char> q;
        int time = 0;
        while(heap.size() || q.size()) {
            if(heap.size()) {
                char current = heap.top();
                heap.pop();
                frequencies[current]--;
                if(frequencies[current] > 0) {
                    q.push(current);
                    delays[current] = time + n;
                }
            }
            
            
            if(q.size() && delays[q.front()] == time) {
                char next = q.front();
                q.pop();
                heap.push(next);
            }
            time++;
        }
        return time;

        


    }
};
