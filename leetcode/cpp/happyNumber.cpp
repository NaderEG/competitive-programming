class Solution {
public:
    int sum_of_digits_squared(int n) {
        int sum = 0;
        while (n != 0) {
            int last = n % 10;
            sum += last*last;
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        set<int> seen_nums;
        while(true) {
            if (n == 1) {
                return true;
            }
            if(seen_nums.count(n) > 0) {
                return false;
            }
            seen_nums.insert(n);
            n = sum_of_digits_squared(n);
            
        }
    }
};
