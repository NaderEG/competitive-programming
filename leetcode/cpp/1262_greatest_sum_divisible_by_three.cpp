class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int sum = 0;
        int res = 0;
        if(nums.size() == 1) {
            if(nums[0] % 3 == 0) {
                return nums[0];
            } else {
                return 0;
            }
        }
        for(int num : nums) {
            sum = sum+num;
        }
        int slack = sum % 3;
        if(slack == 0) {
            return sum;
        }
        else if(slack == 1) {
            for (int num : nums) {
                if(num % 3 == 1) {
                    res = max(res, sum - num);
                }
            }
            int smallest = 100000;
            int secondSmallest = 100000;
            for (int x : nums) {
                if (x < smallest && x % 3 == 2) {
                    secondSmallest = smallest;
                    smallest = x;
                } else if (x < secondSmallest && x % 3 == 2) {
                    secondSmallest = x;
                }
            }
            res = max(res, sum - smallest - secondSmallest);
        } else if(slack == 2) {
            for (int num : nums) {
                if(num % 3 == 2) {
                    res = max(res, sum - num);
                }
            }
            int smallest = 100000;
            int secondSmallest = 100000;
            for (int x : nums) {
                if (x < smallest && x % 3 == 1) {
                    secondSmallest = smallest;
                    smallest = x;
                } else if (x < secondSmallest && x % 3 == 1) {
                    secondSmallest = x;
                }
            }
            res = max(res, sum - smallest - secondSmallest);
        }
        return res;
    }
};