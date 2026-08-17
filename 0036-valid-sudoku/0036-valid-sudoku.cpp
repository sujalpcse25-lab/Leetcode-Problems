class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // 9 rows, 9 columns, and 9 sub-boxes
        bool row[9][9] = {false};
        bool col[9][9] = {false};
        bool box[9][9] = {false};
        
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] == '.') continue;  // skip empty cells
                
                int num = board[r][c] - '1';  // digit 1-9 -> index 0-8
                int boxIndex = (r / 3) * 3 + (c / 3);  // compute sub-box index
                
                // Check for duplicates
                if (row[r][num] || col[c][num] || box[boxIndex][num])
                    return false;
                    
                row[r][num] = true;
                col[c][num] = true;
                box[boxIndex][num] = true;
            }
        }
        return true;
    }
};