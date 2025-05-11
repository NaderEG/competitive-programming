def permutes(s1, s2):
        return sorted(s1) == sorted(s2)

class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        l = 0
        r = len(s1) - 1

        while r < len(s2):
            if permutes(s2[l:r+1], s1):
                return True
            r+=1
            l+=1
        return False