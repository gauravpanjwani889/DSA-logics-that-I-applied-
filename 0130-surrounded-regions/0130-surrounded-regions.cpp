class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();

        queue<pair<int,int>> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
               if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                    if (board[i][j] == 'O') {
                        q.push({i, j});
                        board[i][j] = '#';
                    }
                }
            }
        }

        int delrow[]={0,-1,0,1};
        int delcol[]={-1,0,1,0};

        

        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
           
            q.pop();

            for(int i=0;i<4;i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && board[nrow][ncol]=='O' ){
                    board[nrow][ncol]='#';
                    q.push({nrow,ncol});
                }
            }

        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X'; // Captured!
                } else if (board[i][j] == '#') {
                    board[i][j] = 'O'; // Escaped, change back to 'O'
                }
            }
        }


        
    }
};