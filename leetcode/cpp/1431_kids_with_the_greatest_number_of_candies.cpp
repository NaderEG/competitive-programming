class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max = 0;
        for (int i : candies) {
            if (i > max) {
                max = i;
            }
        }
        cout << max;
        vector<bool> result; 
        for (int j = 0; j < candies.size(); j++) {
            if (candies[j] + extraCandies >= max) {
                result.push_back(true);
            } else {
                result.push_back(false);
            }
        } 
        return result;
    }
};