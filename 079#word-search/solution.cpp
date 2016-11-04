class Solution {
    bool check(vector<vector<char>>& board, int i, int j, string::iterator p, string::iterator e) {
        if (*p != board[i][j]) {
            return false;
        }
        if (++p == e) {
            return true;
        }
        char c = board[i][j];
        board[i][j] = 0;
        if (i > 0 && check(board, i - 1, j, p, e)) {
            board[i][j] = c;
            return true;
        }
        if (j > 0 && check(board, i, j - 1, p, e)) {
            board[i][j] = c;
            return true;
        }
        if (i < board.size() - 1 && check(board, i + 1, j, p, e)) {
            board[i][j] = c;
            return true;
        }
        if (j < board.front().size() - 1 && check(board, i, j + 1, p, e)) {
            board[i][j] = c;
            return true;
        }
        board[i][j] = c;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty() || word.empty()) {
            return false;
        }
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board.front().size(); j++) {
                if (check(board, i, j, word.begin(), word.end())) {
                    return true;
                }
            }
        }
        return false;
        
    }
};