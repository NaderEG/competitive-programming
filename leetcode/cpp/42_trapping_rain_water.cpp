using std::min;

class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> prefix;
        vector<int> suffix;
        int max = 0;
        for (int i = 0; i < height.size(); i++) {
            if (height[i] > max) {
                max = height[i];
            }
            prefix.push_back(max);
        }
        max = 0;
        for (int j = height.size()-1; j >= 0; j--) {
            if (height[j] > max) {
                max = height[j];
            }
            suffix.insert(suffix.begin(), max);
        }
        int result = 0;
        for (int k = 0; k < height.size(); k++) {
            result += min(prefix[k], suffix[k])-height[k];
        }
        return result;
    }
};
