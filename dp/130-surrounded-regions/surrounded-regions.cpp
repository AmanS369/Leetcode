class Solution {
public:
    int dirs[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
    
    void bfs(vector<vector<char>>& board, int i, int j) {
        int m = board.size(), n = board[0].size();
        queue<pair<int,int>> q;
        q.push({i,j});
        board[i][j] = 'S';
        
        while(!q.empty()) {
            auto [x,y] = q.front(); q.pop();
            for(auto &d: dirs) {
                int nx = x + d[0], ny = y + d[1];
                if(nx>=0 && ny>=0 && nx<m && ny<n && board[nx][ny]=='O') {
                    board[nx][ny] = 'S';
                    q.push({nx,ny});
                }
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if(m==0) return;
        int n = board[0].size();

        // Borders
        for(int i=0;i<m;i++){
            if(board[i][0]=='O') bfs(board,i,0);
            if(board[i][n-1]=='O') bfs(board,i,n-1);
        }
        for(int j=0;j<n;j++){
            if(board[0][j]=='O') bfs(board,0,j);
            if(board[m-1][j]=='O') bfs(board,m-1,j);
        }

        // Final conversion
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O') board[i][j]='X';
                else if(board[i][j]=='S') board[i][j]='O';
            }
        }
    }
};
