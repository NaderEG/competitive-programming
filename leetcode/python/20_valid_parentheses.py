class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        stack = []

        for i in s:
            if i == "(" or i == "{" or i == "[":
                stack.append(i)
            elif not stack:
                return False
            elif i == ")": 
                if stack.pop() != "(":
                    return False
            elif i == "}": 
                if stack.pop() != "{":
                    return False
            elif i == "]":
                if stack.pop() != "[":
                    return False
        return len(stack) == 0
