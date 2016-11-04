class Solution {
    int get(vector<vector<int>>& board, int i, int j) {
        return i >= 0 && i < board.size() && j >= 0 && j < board[i].size() ? board[i][j] : 0;
    }
public:
    void gameOfLife(vector<vector<int>>& board) {
        if (board.size() == 0) {
            return;
        }
        int h = board.size(), w = board.front().size();
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                int c = (get(board, i - 1, j - 1) >> 1)
                      + (get(board, i - 1, j) >> 1)
                      + (get(board, i - 1, j + 1) >> 1)
                      + (get(board, i, j - 1) >> 1)
                      + (get(board, i, j + 1))
                      + (get(board, i + 1, j - 1))
                      + (get(board, i + 1, j))
                      + (get(board, i + 1, j + 1));
                
                board[i][j] = (board[i][j] << 1) | (board[i][j] == 1 && (c == 2 || c == 3) || board[i][j] == 0 && c == 3 ? 1 : 0);
            }
        }
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                board[i][j] &= 1;
            }
        }
    }
};