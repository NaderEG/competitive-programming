class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int curr_digit = digits.size()-1;
        int carry_over = 1;
        while(curr_digit >= 0) {
            if(digits[curr_digit] + carry_over <= 9) {
                digits[curr_digit]+=1;
                return digits;
            } else {
                digits[curr_digit] = 0;
                carry_over=1;
            }
            curr_digit--;
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
