class Solution {
    void bfs(int r,int c,vector<vector<int>> &vis, vector<vector<char>>& grid){
        vis[r][c]=1;

        int n=grid.size();
        int m=grid[0].size();

        

        queue<pair<int,int>> q;

        q.push({r,c});

        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;

            q.pop();

            //traverse in neighbors

           int dRow[] = {-1, 1, 0, 0};
int dCol[] = {0, 0, -1, 1};

for(int i = 0; i < 4; i++) {
    int nrow = row + dRow[i];
    int ncol = col + dCol[i];


                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]=='1' && !vis[nrow][ncol]){
                        vis[nrow][ncol]=1;
                        q.push({nrow,ncol});
                    }
                }
            }
        }


        
    
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        

        vector<vector<int>> vis(n,vector<int>(m,0));
        int cnt=0;

        for(int r=0; r<n; r++){
            for(int c=0;c<m;c++){
                if(vis[r][c]==0 && grid[r][c]=='1'){
                    cnt++;
                    bfs(r,c,vis,grid);
                }
            }
        }


        return cnt;


        
    }
};