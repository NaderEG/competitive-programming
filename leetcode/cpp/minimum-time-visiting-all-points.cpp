class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int res = 0;
        for(int i = 0; i < points.size()-1; i++) {
            int prep_x = abs(points[i][0] - points[i+1][0]);
            int prep_y = abs(points[i][1] - points[i+1][1]);
            res += max(prep_x, prep_y);
            
        }
        return res;


    }
};