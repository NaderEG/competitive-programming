class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left = 0;
        int right = 1;
        int num_fruits = 1;
        int max_num_fruits = 1;
        unordered_map<int, int> selection;
        selection[fruits[0]] = 1;
        while(right < fruits.size()) {
            if(right < fruits.size()) {
                if(selection[fruits[right]] == 0) num_fruits++;
                selection[fruits[right]]++;
                right++;
            } 
            while(num_fruits > 2) {
                selection[fruits[left]]--;
                if(selection[fruits[left]] == 0) num_fruits--;
                left++;
            }
            max_num_fruits = max(max_num_fruits, right-left);
        }
        return max_num_fruits;
    }
};