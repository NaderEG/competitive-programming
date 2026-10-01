class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        l = 0
        r = 0
        longest = 1

        if not s:
            return 0

        while r < len(s):
            if s[r] in s[l:r]:
                l += 1
            else:
                r+=1
                if len(s[l:r]) > longest:
                    longest = len(s[l:r])
        return longest