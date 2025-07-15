class Solution {
public:
    bool isValid(string word) {
        int character_count = 0;
        bool has_vowel = false;
        bool has_cons = false;
        for(char letter : word) {
            if(!((letter >= 48 && letter <= 57) || (letter >= 65 && letter <= 90) || (letter >= 97 && letter <= 122))) {
                return false;
            }
            character_count++;
            if(!(letter >= 48 && letter <= 57)) {

                if(letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u' || letter == 'A' || letter == 'E' || letter == 'I' || letter == 'O' || letter == 'U') {
                    has_vowel = true;
                } else {
                    has_cons = true;
                }
            } 
        }
        return has_vowel && has_cons && character_count >= 3;
    }
};