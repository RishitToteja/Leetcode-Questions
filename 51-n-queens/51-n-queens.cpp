class Solution {
public:
    int board[10][10];
    vector<vector<string>>arr;
    
    bool check(int n, int row, int col){
        
        for(int i=row-1; i>=0; i--){
            if(board[i][col]==1)
                return false;
        }
        for(int i=row-1, j = col-1; i>=0&&j>=0; i--, j--){
            if(board[i][j]==1)
                return false;
        }
        for(int i=row-1, j = col+1; i>=0&&j<n; i--, j++){
            if(board[i][j]==1)
                return false;
        }
        return true;
        
    }
    void helper(int n, int row){
        if(row==n){
            vector<string>temp;
            for(int i=0; i<n; i++){
                string s = "";
                for(int j=0; j<n; j++){
                    if(board[i][j]==1)
                        s += 'Q';
                    else
                        s += '.';
                }
                temp.push_back(s);
            }
            arr.push_back(temp);
        }
        
        else{
            for(int j=0; j<n; j++){
                if(check(n, row, j)){
                    board[row][j]=1;
                    helper(n, row+1);
                    board[row][j]=0;
                }
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        memset(board, 0, sizeof(board));
        helper(n, 0);
        return arr;
    }
};