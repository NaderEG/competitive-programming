class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        

        stack = []

        for t in tokens:
            if t == "/":
                si = stack.pop()
                fi = stack.pop()
                stack.append(int(fi/si))
            
            elif t == "+":
                si = stack.pop()
                fi = stack.pop()
                stack.append(fi+si)

            elif t == "-":
                si = stack.pop()
                fi = stack.pop()
                stack.append(fi-si)

            elif t == "*":
                si = stack.pop()
                fi = stack.pop()
                stack.append(fi*si)
            else:
                stack.append(int(t))
        return stack[0]
