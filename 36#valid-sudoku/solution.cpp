class Solution {
public:
    int col[9], row[9], region[9]; //Bit set of each column, row and region
    bool isValidSudoku(vector<vector<char>>& board) {
        int i, j, k, c; // The current row, column, region index we accessed
        int b; // The temporary bit set
        for (i = 0; i < 9; i++)
        {
            col[i] = row[i] = region[i] = 0777; // Binary number 111111111
        }
        for (i = 0; i < 9; i++)
        {
            for(j = 0; j < 9; j++)
            {
                c = board[i][j] == '.' ? 0 : board[i][j] - '0';
                if (c > 0) {
                    k = (i / 3) * 3 + (j / 3);
                    b = (1 << c) >> 1;
                    if ((b & row[i] & col[j] & region[k]) == 0) {
                        return false;
                    }
                    b = ~b;
                    row[i] &= b;
                    col[j] &= b;
                    region[k] &= b;
                }
            }
        }
        return true;
    }
};
