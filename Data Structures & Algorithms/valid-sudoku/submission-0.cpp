class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> rows(9, vector<bool>(9, false));
        vector<vector<bool>> columns(9, vector<bool>(9, false));
        vector<vector<bool>> boxs(9, vector<bool>(9, false));

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == '.') {
                    continue;
                }

                int box_index = (i / 3) * 3 + (j / 3);
                int value = board[i][j] - '1';

                if (rows[i][value] || columns[j][value] || boxs[box_index][value]) {
                    return false;
                }
                
                rows[i][value] = true;
                columns[j][value] = true;
                boxs[box_index][value] = true;
            }
        }

        return true;
    }
};
