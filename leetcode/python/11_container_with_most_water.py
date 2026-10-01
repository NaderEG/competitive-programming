class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        maxW = 0
        base = len(height)-1

        left = 0
        right = len(height)-1

        while(base > 0):
            if height[left] > height[right]:
                if height[right]*base > maxW:
                    maxW = height[right]*base
                right-=1
                base-=1
            else:
                if height[left]*base > maxW:
                    maxW = height[left]*base
                left+=1
                base-=1

        return maxW
        
                
