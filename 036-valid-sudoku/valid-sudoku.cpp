// Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.
//
// The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
//
//
//
// A partially filled sudoku which is valid.
//
//
// Note:
// A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
//


class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //代表每一行、列、小九格被使用的状态
        vector<vector<bool>> used_row(9, vector<bool>(9, false));
        bool used_column[9][9] = {false};
        bool used_smallsquare[9][9] = {false};
        
        for(int i=0;i<9;i++) {
            for(int j=0;j<9;j++) {
                if(board[i][j]!='.') {
                    if(used_row[i][board[i][j]-'0'-1]||used_column[j][board[i][j]-'0'-1]||used_smallsquare[i/3*3+j/3][board[i][j]-'0'-1])
                        return false;
                    used_row[i][board[i][j]-'0'-1]=true;
                    used_column[j][board[i][j]-'0'-1]=true;
                    used_smallsquare[i/3*3+j/3][board[i][j]-'0'-1]=true;
                }
            }
        }
        
        return true;
    }
};
