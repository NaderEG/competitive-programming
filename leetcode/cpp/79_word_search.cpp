class Solution {
public:
    bool out_of_bounds(int i, int j, int height, int width) {
        return i >= height || i < 0 || j >= width || j < 0;
    }

    bool search(int letter, string word, int i, int j, vector<vector<char>>& board, set<pair<int, int>> visited) {
        if(word[letter] != board[i][j]) {
            return false;
        }
        if(letter == word.length()-1) {
            return true;
        }
        bool up, down, left, right;
        up = false;
        down = false;
        left = false;
        right = false;
        visited.insert({i, j});
        if(!out_of_bounds(i+1, j, board.size(), board[0].size()) && visited.find({i+1, j}) == visited.end()) {
            down = search(letter+1, word, i+1, j, board, visited);
        }
        if(!out_of_bounds(i-1, j, board.size(), board[0].size()) && visited.find({i-1, j}) == visited.end()) {
            up = search(letter+1, word, i-1, j, board, visited);
        }
        if(!out_of_bounds(i, j+1, board.size(), board[0].size()) && visited.find({i, j+1}) == visited.end()) {
            right = search(letter+1, word, i, j+1, board, visited);
        }
        if(!out_of_bounds(i, j-1, board.size(), board[0].size()) && visited.find({i, j-1}) == visited.end()) {
            left = search(letter+1, word, i, j-1, board, visited);
        }
        return left || right || up || down;
        

    }

    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[i].size(); j++) {
                if(search(0, word, i, j, board, set<pair<int, int>>())) {
                    return true;
                }
            }
        }
        return false;
    }
};
