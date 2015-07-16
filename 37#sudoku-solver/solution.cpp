class Solution {
public:
    int empty[81]; // The index of each empty gird
    int col[9], row[9], region[9]; //Bit set of each column, row and region
    char map[81];
    void solveSudoku(vector<vector<char>>& board) {
        int c = 0;  // The current index we accessed
        int i, j, k; // The current row, column, region index we accessed
        int b; // The temporary bit set
        int empty_count = 0; // The count of empty gird
        int filled = 0; // The count of filled empty gird
        for (i = 0; i < 9; i++)
        {
            col[i] = row[i] = region[i] = 0777; // Binary number 111111111
        }
        for (i = 0; i < 9; i++)
        {
            for(j = 0; j < 9; j++)
            {
                c = i * 9 + j;
                map[c] = board[i][j] == '.' ? 0 : board[i][j] - '0';
                k = (i / 3) * 3 + (j / 3);
                if (map[c] > 0) {
                    b = (1 << map[c]) >> 1;
                    b = ~b;
                    row[i] &= b;
                    col[j] &= b;
                    region[k] &= b;
                } else {
                    empty[empty_count++] = i * 9 + j;
                }
            }
        }
        while (filled < empty_count) //Fill numbers until all number has been filled
        {
            c = empty[filled];
            i = c / 9;
            j = c % 9;
            k = (c / 27) * 3 + ((c % 9) / 3);
            if (map[c] > 0)  //If this gird has been filled before, then reset it
            {
                b = (1 << map[c]) >> 1; //Reset the bit to 1
                row[i] |= b;
                col[j] |= b;
                region[k] |= b;
            }
            while (map[c] <= 9) //Fill current gird if the number was not appeared in current row, col or region
            {
                map[c] ++;
                b = (1 << map[c]) >> 1; //Get the bit of the number and check if it has alerdy existed.
                if (row[i] & col[j] & region[k] & b)
                {
                    break;
                }
            }
            if (map[c] > 9) // If there is no number to fill, back to the gird we filled before
            {
                map[c] = 0;
                filled--;
                if (filled < 0) // If current is the first gird, then there is no answer for the puzzle
                {
                    return;
                }
            }
            else
            {
                b = ~((1 << map[c]) >> 1); //After we filled this gird, set the bit to 0
                row[i] &= b;
                col[j] &= b;
                region[k] &= b;
                filled++;
            }
        }
        for (i = 0; i < 9; i++)
        {
            for(j = 0; j < 9; j++)
            {
                c = i * 9 + j;
                board[i][j] = map[c] + '0';
            }
        }
    }
};
