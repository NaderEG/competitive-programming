
using std::unordered_map;
using std::set;

class Solution {
public:
    bool has_duplicates(const vector<char> vec) {
        unordered_set<char> seen;
        for (char num : vec) {
            if (seen.find(num) != seen.end()) {
                return true;
            }
            seen.insert(num);
        }
        return false;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, vector<char>> cols;
        unordered_map<int, vector<char>> rows;
        unordered_map<int, vector<char>> sqs;

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    rows[i].push_back(board[i][j]);
                    cols[j].push_back(board[i][j]);
                    sqs[(i/3)*3+j/3].push_back(board[i][j]);
                }
            }
        }
        for (auto const& [key, val] : rows) {
            if (has_duplicates(rows[key])) {
                return false;
            }
        }
        for (auto const& [key1, val1] : cols) {
            if (has_duplicates(cols[key1])) {
                return false;
            }
        }
        for (auto const& [key2, val2] : sqs) {
            if (has_duplicates(sqs[key2])) {
                return false;
            }
        }
        return true;
    }
};
