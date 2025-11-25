class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if (k % 2 == 0 || k % 5 == 0) return -1;
        int length = 1;
        int num = 1 % k;
        while(length <= k) {
            if(num == 0) {
                return length;
            }
            num = (num*10 + 1) % k;
            length++;
        }
        return -1;
    }
};