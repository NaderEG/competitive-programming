class Solution {
public:
    

    string getHappyString(int n, int k) {
        vector<string> happy_strings;
        vector<char> index = {'a', 'b', 'c'};
        queue<string> q;
        q.push("a");
        q.push("b");
        q.push("c");

        while(happy_strings.size() < k && q.size()) {
            string current = q.front();
            q.pop();
            if(current.size() == n) {
                happy_strings.push_back(current);
            } else {
                for(int i = 0; i < 3; i++) {
                    if(index[i] != current[current.size()-1]) {
                        q.push(current+index[i]);
                    }
                }
            }
            
            
        }
        if(k > happy_strings.size()) {
            return "";
        }
        return happy_strings[k-1];
    }
};