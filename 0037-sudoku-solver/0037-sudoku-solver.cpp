class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
    
private:
    bool solve(vector<vector<char>>& board) {
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                // Find an empty cell
                if (board[r][c] == '.') {
                    // Try each digit 1-9
                    for (char digit = '1'; digit <= '9'; digit++) {
                        if (isValid(board, r, c, digit)) {
                            board[r][c] = digit;  // place the digit
                            
                            if (solve(board))      // recurse
                                return true;
                                
                            board[r][c] = '.';     // backtrack (undo)
                        }
                    }
                    return false;  // no valid digit works, need to backtrack
                }
            }
        }
        return true;  // all cells filled -> solved
    }
    
    bool isValid(vector<vector<char>>& board, int row, int col, char digit) {
        // Partial validation for the newly placed digit
        for (int i = 0; i < 9; i++) {
            // Check row
            if (board[row][i] == digit) return false;
            // Check column
            if (board[i][col] == digit) return false;
            // Check 3x3 sub-box
            int boxRow = 3 * (row / 3) + i / 3;
            int boxCol = 3 * (col / 3) + i % 3;
            if (board[boxRow][boxCol] == digit) return false;
        }
        return true;
    }
};