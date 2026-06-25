class Solution {
    bool issafe(vector<string> &board, int row, int col, int n){
        //horizontal

        for(int j=0;j<n;j++){
            if(board[row][j]=='Q'){
                return false;

            }
        }
        for(int j=0;j<n;j++){
            if(board[j][col]=='Q'){
                return false;

            }
        }

        //lftdiag
        for(int i=row,j=col;i>=0 && j>=0 ; i--,j--){
            if(board[i][j]=='Q'){
                return false;
            }
        }
        for(int i=row, j=col;i>=0 && j>=0 ; i--,j++){
            if(board[i][j]=='Q'){
                return false;
            }
        }


        return true;

        

    }
    void func(vector<string> &board, vector<vector<string>> &ans, int row, int n){
        if(row==n){
            ans.push_back(board);
            return;
        }

        for(int j=0;j<n;j++){
            if(issafe(board,row,j,n)){
                
            board[row][j]='Q';
            func(board,ans,row+1,n);
            board[row][j]='.';

            }


        }
    }
public: 

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        vector<vector<string>> ans;
        func(board, ans,0,n);
        return ans;



        
    }
};