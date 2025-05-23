class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> indices;
        vector<int> height;
        int maxArea = 0;

        for(int i = 0; i < heights.size(); ++i) {
            if(height.size() && heights[i] < height.back()) {
                int index;
                while(height.size() && heights[i] < height.back()) {
                    int length = height.back();
                    int width = i - indices.back();
                    maxArea = length * width > maxArea ? length*width : maxArea;
                    height.pop_back();
                    index = indices.back();
                    indices.pop_back();
                    
                }
                height.push_back(heights[i]);
                indices.push_back(index);
            } else {
                indices.push_back(i);
                height.push_back(heights[i]);
            }
        }
        int i = heights.size();
        while(indices.size()) {
            int length = height.back();
            int width = i - indices.back();
            maxArea = length * width > maxArea ? length*width : maxArea;
            height.pop_back();
            indices.pop_back();
        }
        return maxArea;
    }
};
