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

    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int> dp(matrix[0].size(), 0);
        int res = 0;
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[i].size(); j++) {
                if(matrix[i][j] == '1') {
                    dp[j] += 1;
                } else {
                    dp[j] = 0;
                }
                
            }
            res = max(res, largestRectangleArea(dp));
        }
        return res;
    }
};