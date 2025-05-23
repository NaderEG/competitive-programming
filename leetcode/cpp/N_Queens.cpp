class Solution {
public:
    vector<vector<string>> answer;
    void placeQueen(int n, int row, set<int> col, set<int> posDiag, set<int> negDiag, vector<string> board) {
        if(row == n) {
            answer.push_back(board);
        }
        for(int i = 0; i < n; i++) {
            if(!(col.count(i) || posDiag.count(row + i) || negDiag.count(row-i))) {
                col.insert(i);
                posDiag.insert(row + i);
                negDiag.insert(row-i);
                string pieces = "";
                for(int j = 0; j < n; j++) {
                    if(j == i) {
                        pieces+="Q";
                    } else {
                        pieces+=".";
                    }
                }
                board.push_back(pieces);
                placeQueen(n, row+1, col, posDiag, negDiag, board);
                col.erase(i);
                posDiag.erase(row + i);
                negDiag.erase(row-i);
                board.pop_back();
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        placeQueen(n, 0, set<int>(), set<int>(), set<int>(), vector<string>());
        return answer;
    }
};
