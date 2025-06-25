class Solution {
public:
    int numberOfChild(int n, int k) {
        int child = 0;
        int time = 0;
        int step = -1;

        while(time < k) {
            if(child == n-1 || child == 0) {
                step*=-1;
            }
            child+=step;
            time++;

        }
        return child;

    }
};