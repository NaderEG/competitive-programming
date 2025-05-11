using std::min;

class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size()-1;

        int max = 0;
        while (left < right) {
            int vol = (right - left)* min(heights[left], heights[right]);
            if(vol > max) {
                max = vol;
            }
            if (heights[left] > heights[right]) {
                right--;
            } else {
                left++;
            }
        }
        return max;
    }
};
