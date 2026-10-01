class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int res = 0;
        // first odd, second even
        bool need_odd = true;
        int count = 0;
        for(int num : nums) {
            if(num % 2 == 1 && need_odd) {
                count++;
                need_odd = false;
            } else if(num % 2 == 0 && !need_odd) {
                count++;
                need_odd = true;
            }
        }
        res = max(res, count);

        // first even, second odd
        bool need_even = true;
        count = 0;
        for(int num : nums) {
            if(num % 2 == 0 && need_even) {
                count++;
                need_even = false;
            } else if(num % 2 == 1 && !need_even) {
                count++;
                need_even = true;
            }
        }
        res = max(res, count);

        // only even
        count = 0;
        for(int num : nums) {
            if(num % 2 == 0) {
                count++;
            }
        }
        res = max(res, count);

        // only odd
        count = 0;
        for(int num : nums) {
            if(num % 2 == 1) {
                count++;
            }
        }
        res = max(res, count);

        return res;

    }
};