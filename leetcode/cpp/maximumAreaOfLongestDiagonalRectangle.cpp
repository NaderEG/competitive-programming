class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int max_diag = 0;
        int max_area = 0;
        for(vector<int> rect : dimensions) {
            int base = rect[0];
            int height = rect[1];
            int diag_len = base*base + height*height;
            if(diag_len > max_diag) {
                max_diag = diag_len;
                max_area = base*height;
            } else if(diag_len == max_diag) {
                max_area = max(max_area, base*height);
            }
        }
        return max_area;
    }
};