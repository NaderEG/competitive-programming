class Solution:

    def encode(self, strs: List[str]) -> str:
        code = ""
        for word in strs:
            code = code + str(len(word)) +"."+ word
        return code

    def decode(self, s: str) -> List[str]:
        strs = []
        while len(s) > 0:
            l = s.split(".", 1)
            n = int(l[0])
            s = l[1]
            s = s[0:]
            strs.append(s[:n])
            s = s[n:]
        return strs