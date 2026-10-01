class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        bool searching = true;
        int word = 1;
        for(int i = 0; i < sentence.length(); i++) {
            int j = 0;
            while(searching && sentence[i+j] == searchWord[j]) {
                j++;
                if(j == searchWord.length()) {
                    return word;
                }
            }
            searching = false;
            if(sentence[i] == ' ') {
                searching = true;
                word++;
            }
        }
        return -1;
    }
};