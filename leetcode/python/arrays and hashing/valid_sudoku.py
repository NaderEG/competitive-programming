class Solution(object):
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """

        cols = {0: [], 1:[], 2:[], 3:[], 4:[], 5:[], 6:[], 7:[],8:[]}
        rows = {0: [], 1:[], 2:[], 3:[], 4:[], 5:[], 6:[], 7:[],8:[]}
        sqs = {0: [], 1:[], 2:[], 3:[], 4:[], 5:[], 6:[], 7:[],8:[]}

        for i in range(9):
            for j in range(9):
                if board[i][j] != ".":
                    rows[i].append(board[i][j])
                    cols[j].append(board[i][j])
                    sqs[(i//3)*3 + j//3].append(board[i][j])

        for key in cols:
            if len(cols[key]) != len(set(cols[key])):
                return False

        for key in rows:
            if len(rows[key]) != len(set(rows[key])):
                return False

        for key in sqs:
            if len(sqs[key]) != len(set(sqs[key])):
                return False
        return True