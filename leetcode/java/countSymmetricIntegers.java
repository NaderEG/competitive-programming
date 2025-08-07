class Solution {
    public int countSymmetricIntegers(int low, int high) {
        int res = 0;
        for(int i = low; i <= high; i++) {
            String s_num = String.valueOf(i);
            if(s_num.length() % 2 == 0) {
                int left_sum = 0;
                int right_sum = 0;
                for(int j = 0; j < s_num.length() / 2; j++) {
                    left_sum = left_sum + s_num.charAt(j);
                }
                for(int k = s_num.length() / 2; k < s_num.length(); k++) {
                    right_sum = right_sum + s_num.charAt(k);
                }
                if(left_sum == right_sum) {
                    res++;
                }
            }
        }
        return res;
    }
}