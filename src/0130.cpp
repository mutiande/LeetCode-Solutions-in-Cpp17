class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (empty(board) || empty(board[0])) return;
        int m = size(board);
        int n = size(board[0]);
        for (int i = 0; i < m; ++i)
        {
            dfs(board, i, 0);
            dfs(board, i, n - 1);
        }
        for (int i = 0; i < n; ++i)
        {
            dfs(board, 0, i);
            dfs(board, m - 1, i);
        }
        for (auto& x : board)
        {
            for (auto& y : x)
            {
                if (y == 'O')
                {
                    y = 'X';
                }
                else if (y == '#')
                {
                    y = 'O';
                }
            }
        }
    }

    void dfs(vector<vector<char>>& board, int i, int j)
    {
        if (board[i][j] == 'O')
        {
            board[i][j] = '#';
            if (i > 0) dfs(board, i - 1, j);
            if (i + 1 < size(board)) dfs(board, i + 1, j);
            if (j > 0) dfs(board, i, j - 1);
            if (j + 1 < size(board[0])) dfs(board, i, j + 1); 
        }
    }
};