class Solution {
public:
    int board[11][11];
    vector<vector<string>>arr;
    bool isPossible(int n, int row, int col){
        for(int i = row-1; i>=0; i--){
            if(board[i][col] == 1){
                return false;
            }
        }
        for(int i = row-1, j = col-1; i>=0&&j>=0; i--, j--){
            if(board[i][j] == 1){
                return false;
            }
        }
        for(int i = row-1, j = col+1; i>=0&&j<n; i--, j++){
            if(board[i][j] == 1){
                return false;
            }
        }

        return true;
    }

    void nQueenHelper(int n, int row){
        if(row == n){
            vector<string>temp;
            for(int i=0; i<n; i++){
                string s = "";
                for(int j=0; j<n; j++){
                    if(board[i][j] == 1)
                        s += 'Q';
                    else
                        s += '.';
                }
                temp.push_back(s);
            }
            
            arr.push_back(temp);
        }

        for(int j=0; j<n; j++){
            if(isPossible(n, row, j)){
                board[row][j] = 1;
                nQueenHelper(n, row+1);
                board[row][j] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        memset(board, 0, 11*11*sizeof(int));
        nQueenHelper(n , 0);
        return arr;
    }
    
    int totalNQueens(int n) {
        return solveNQueens(n).size();
    }
};