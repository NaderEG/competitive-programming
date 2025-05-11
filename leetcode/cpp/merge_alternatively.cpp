class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i = 0;
        string newString = "";
        int word1length = word1.length();
        int word2length = word2.length();
        while (i < word1length || i < word2length) {
            if(i < word1length) {
                newString+=word1[i];
            }
            if (i < word2length) {
                newString+=word2[i];
            }
            i++;
        }
        return newString;
    }
};