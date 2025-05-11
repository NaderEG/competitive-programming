class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int top = 0;
        int bottom = matrix.size()-1;
        int mid;
        while (top <= bottom) {
            mid = (top + bottom) / 2;
            if(matrix[mid][matrix[mid].size()-1] < target) {
                top = mid+1;
            } else if (matrix[mid][0] > target) {
                bottom = mid-1;
            } else {
                break;
            }
        }
        int left = 0; 
        int right = matrix[mid].size()-1;
        

        while (left <= right) {
            int mid2 = (left + right) / 2;
            if (matrix[mid][mid2] > target) {
                right = mid2-1;
            } else if (matrix[mid][mid2] < target) {
                left = mid2+1;
            } else {
                return true;
            }
        }
        return false;

    }
};
