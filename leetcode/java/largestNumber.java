class Solution {
    public String largestNumber(int[] nums) {
        String[] arr = new String[nums.length];
        for(int i = 0; i < nums.length; i++) {
            arr[i] = String.valueOf(nums[i]);
        }
        Arrays.sort(arr, (num1, num2) -> {
            return (num2+num1).compareTo(num1+num2);
        });
        String res = "";
        for(String num : arr) {
            res += num;
        }
        if (res.charAt(0) == '0') return "0";
        return res;
    }
}