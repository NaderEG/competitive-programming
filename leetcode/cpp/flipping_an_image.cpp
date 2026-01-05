class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n = image[0].size();
        int half_way = (n - 1) / 2;
        
        for(auto& row : image) {
            for(int i = 0; i <= half_way; i++) {
                int temp = row[i];
                row[i] = row[n - 1 - i];
                row[n - 1 - i] = temp;
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(image[i][j] == 1) {
                    image[i][j] = 0;
                } else {
                    image[i][j] = 1;
                }
            }
        }
        return image;
    }
};