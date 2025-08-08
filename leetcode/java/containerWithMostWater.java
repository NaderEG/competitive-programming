class Solution {
    public int maxArea(int[] height) {
        int left = 0;
        int right = height.length-1;
        int max_vol = 0;
        while(left < right) {
            int current_vol = Math.min(height[left], height[right]) * (right - left);
            max_vol = Math.max(current_vol, max_vol);

            if(height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return max_vol;
    }
}