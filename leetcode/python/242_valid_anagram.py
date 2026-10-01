class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        t_list = sorted(t)
        s_list = sorted(s)
        print(t_list)
        print(s_list)
        return t_list == s_list
        