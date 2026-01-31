class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        auto it = upper_bound(letters.begin(), letters.end(), target);

        if (it != letters.end()) {
            size_t index = distance(letters.begin(), it);
            return letters[index];
        } else {
            return letters[0];
        }
    }
};