import re

class Solution(object):
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        newString = re.sub(r'[^a-zA-Z0-9]', '', s.lower())

        half = len(newString)//2

        for i in range(half):
            if newString[i] != newString[-(i+1)]:
                return False
        return True
        
        