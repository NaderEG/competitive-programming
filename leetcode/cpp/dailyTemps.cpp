class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size());
        vector<int> stack;

        for (int i = 0; i < temperatures.size(); i++) {
            while(stack.size() > 0 && temperatures[i] > temperatures[stack.back()]) {
                int popped_index = stack.back();
                stack.pop_back();
                result[popped_index] = i - popped_index;
            }
            stack.push_back(i);
        }
        return result;
    }
};
