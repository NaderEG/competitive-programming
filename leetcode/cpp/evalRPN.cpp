class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> stack;
        for (string token : tokens) {
            if (token == "*" || token == "/" || token == "+" || token == "-") {
                int num1 = stack.back();
                stack.pop_back();
                int num2 = stack.back();
                stack.pop_back();
                if(token == "*") stack.push_back(num1*num2);
                if(token == "/") stack.push_back(num2/num1);
                if(token == "+") stack.push_back(num1+num2);
                if(token == "-") stack.push_back(num2-num1);
            } else {
                stack.push_back(stoi(token));
            }
        }
        return stack.back();
    }
};
