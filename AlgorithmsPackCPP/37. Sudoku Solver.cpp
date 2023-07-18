int rows[9][9]{0};
int cols[9][9]{0};
int box[3][3][9]{0};
vector<int>emptyRow;
vector<int>emptyCol;

class Solution {
public:
    void solveSudoku(vector<vector<char>>&board) {
        memset(rows,0,sizeof(rows));
        memset(cols,0,sizeof(cols));
        memset(box,0,sizeof(box));
        emptyRow.clear();
        emptyCol.clear();

        // mark initial reserved values
        for (int r = 0; r < 9; r++){
            for (int c = 0; c < 9; c++){
                if (board[r][c] != '.')
                    set(board[r][c] - '1', r, c, 1);
                else {
                    emptyRow.push_back(r);
                    emptyCol.push_back(c);
                }
            }
        }
        assert(backtrack(board, 0));
    }

    bool backtrack(vector<vector<char>>&board, int idx) {
        if (idx >= (int) emptyRow.size())
            return true;

        int r = emptyRow[idx];
        int c = emptyCol[idx];

        for (int d = 0; d < 9; d++) {
            if (canPlace(d, r, c)) {
                set(d, r, c, 1);
                board[r][c] = d + '1';

                if (backtrack(board, idx + 1))
                    return true;

                set(d, r, c, 0);
                board[r][c] = '.';
            }
        }
        return false;
    }
    bool canPlace(int d, int r, int c) {
        return !rows[r][d] && !cols[c][d] && !box[r / 3][c / 3][d];
    }
    void set(int d, int r, int c, int value) {
        rows[r][d] = cols[c][d] = box[r / 3][c / 3][d] = value;
    }
};