class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        result = [0] * len(temperatures)
        stack = []

        for i, t in enumerate(temperatures):
            if i == len(temperatures)-1:
                return result
            stack.append((i, t))
            while stack and temperatures[i+1] > stack[-1][1]:
                temp = stack.pop()
                result[temp[0]] = i-temp[0]+1