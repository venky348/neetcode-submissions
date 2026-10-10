class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        map<int, set<int>> cols;
        map<int, set<int>> rows;
        map<pair<int, int>, set<int>> sqaures;

        for(int r = 0; r < 9; r++){
            for(int c = 0; c < 9; c++){
                if (board[r][c] == '.'){
                    continue;
                }
                if (cols[c].find(board[r][c]) != cols[c].end() ||
                    rows[r].find(board[r][c]) != rows[r].end() ||
                    sqaures[{r/3, c/3}].find(board[r][c]) != sqaures[{r/3, c/3}].end()) {
                        return false;
                    }
                cols[c].insert(board[r][c]);
                rows[r].insert(board[r][c]);
                sqaures[{r/3, c/3}].insert(board[r][c]);
            }
        }

        return true;
    }
};
