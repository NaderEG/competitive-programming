import string

class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        l = 0
        r = 0
        letters = {letter: 0 for letter in string.ascii_uppercase}
        letters[s[0]] += 1
        res = 0

        while r < len(s):
            most_common = max(letters.values())
            win_len = r - l + 1
            
            if win_len - most_common <= k and win_len > res:
                res = win_len
            
            if win_len - most_common > k:
                letters[s[l]] -= 1
                l += 1
            else:
                r += 1
                if r < len(s):
                    letters[s[r]] +=1
                
            print(res)
        return res
            
