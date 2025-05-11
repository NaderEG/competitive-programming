class Solution {
public:
    bool isValidSpeed(vector<int>& piles, int k, int h) {
        int time = 0;
        for (int num : piles) {
            time += std::ceil((double)num/k);
        }
        return time <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int x = 1;
        for (int num_bananas : piles) {
            if (num_bananas > x) {
                x = num_bananas;
            }
        }
        // [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25]

        int left = 1;
        int right = x;
        while (left < right) {
            int mid = (left+ right) / 2;
            if (isValidSpeed(piles, mid, h)) {
                right = mid;
            } else {
                left = mid+1;
            }
        }
        return left;
    }
};