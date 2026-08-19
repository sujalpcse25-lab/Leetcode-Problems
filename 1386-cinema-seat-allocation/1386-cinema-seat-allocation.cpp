class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> rowMask; 
        // Each row will be represented as a bitmask of reserved seats

        for (auto &seat : reservedSeats) {
            int row = seat[0], col = seat[1];
            rowMask[row] |= (1 << col); 
            // Mark seat as reserved in that row
        }

        int totalGroups = 0;

        for (auto &[row, mask] : rowMask) {
            bool left = !(mask & ((1 << 2) | (1 << 3) | (1 << 4) | (1 << 5)));
            bool middle = !(mask & ((1 << 4) | (1 << 5) | (1 << 6) | (1 << 7)));
            bool right = !(mask & ((1 << 6) | (1 << 7) | (1 << 8) | (1 << 9)));

            if (left && right) {
                totalGroups += 2;
            } else if (left || middle || right) {
                totalGroups += 1;
            }
        }

        // Rows without any reserved seats can seat 2 groups
        totalGroups += (n - rowMask.size()) * 2;

        return totalGroups;
    }
};
