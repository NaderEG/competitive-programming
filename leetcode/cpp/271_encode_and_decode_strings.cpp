#include <iostream>
using std::string;

class Solution {
public:

    string encode(vector<string>& strs) {
        string coded = "";
        for (string word : strs) {
            coded = coded + to_string(word.length()) + "." + word;
        }
        return coded;
    }

    vector<string> decode(string s) {
        vector<string> result;
        int pos = s.find('.');
        while(pos != string::npos) {
            string t = s.substr(0, pos);
            cout << s << "\n";
            s = s.substr(pos+1);

            int length = stoi(t);

            result.push_back(s.substr(0, length));
            s = s.substr(length);
            pos = s.find('.');
        }
        return result;
    }
};
