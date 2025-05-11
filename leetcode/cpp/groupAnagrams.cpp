using std::vector;
using std::unordered_map;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // initialize an unordered map<string, vector<string>>
        unordered_map<string, vector<string>> umap;
        // loop through all strings and append them with the key of their sorted value
        for (string str : strs) {
            string sortedWord = str;
            sort(sortedWord.begin(), sortedWord.end());
            if (umap.count(sortedWord) > 0) {
                umap[sortedWord].push_back(str);
            } else {
                umap[sortedWord] = vector<string>{str};
            }
        }
        // initialize an empty vector
        vector<vector<string>> result;
        //go through the dictionary and append each vector
        for (auto const& x : umap) {
            result.push_back(x.second);
        }
        return result;


    }
};
