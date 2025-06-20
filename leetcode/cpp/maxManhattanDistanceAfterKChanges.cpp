class Solution {
public:
    int maxDistInMonoPath(string path, char x_dir, char y_dir, char x_bad, char y_bad, int k) {
        int max_dist = 0;
        int hor_dist = 0;
        int vert_dist = 0;
        for(char step : path) {
            if(step == x_dir) {
                hor_dist++;
            }
            else if(step == y_dir) {
                vert_dist++;
            }
            else if(step == y_bad) {
                if(k > 0) {
                    vert_dist++;
                    k--;
                } else {
                    vert_dist--;
                }
            } else if(step == x_bad) {
                if(k > 0) {
                    hor_dist++;
                    k--;
                } else {
                    hor_dist--;
                }
            }
            max_dist = max(max_dist, vert_dist + hor_dist);
        }
        return max_dist;
        
    }

    int maxDistance(string s, int k) {
        int max_dist = 0;
        int NE_max = maxDistInMonoPath(s, 'E', 'N', 'W', 'S', k);
        int NW_max = maxDistInMonoPath(s, 'W', 'N', 'E', 'S', k);
        int SW_max = maxDistInMonoPath(s, 'W', 'S', 'E', 'N', k);
        int SE_max = maxDistInMonoPath(s, 'E', 'S', 'W', 'N', k);
        return max({max_dist, NE_max, NW_max, SW_max, SE_max});
    }
};