class Solution {
public:
    bool box(vector<vector<char>>& board, int ri, int re, int ci, int ce){
        vector<int>arr(10, 0);
        for(int i=ri; i<=re; i++){
            for(int j=ci; j<=ce; j++){
                if(board[i][j]!='.'){
                    arr[board[i][j]-'0']++;
                }   
            }
        }
        for(int i=0; i<arr.size(); i++){
            cout<<arr[i]<<" ";
            if(arr[i]>1)
                return false;
        }
        return true;
    }
    
    bool hor(vector<vector<char>>& board, int r, int si, int ei){
        vector<int>arr(10, 0);
        for(int i=si; i<=ei; i++){
            if(board[r][i]!='.'){
                    arr[board[r][i]-'0']++;
                }
        }
        for(int i=0; i<arr.size(); i++){
            if(arr[i]>1)
                return false;
        }
        return true;
    }
    bool vert(vector<vector<char>>& board, int c, int si, int ei){
        vector<int>arr(10, 0);
        for(int i=si; i<=ei; i++){
            if(board[i][c]!='.'){
                arr[board[i][c]-'0']++;
                       
            }
        }
        for(int i=0; i<arr.size(); i++){
            if(arr[i]>1)
                return false;
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        // for(int i=0; i<9; i++){
        //     for(int j=0; j<9; j++){
        //         cout<<board[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        bool bol= true;        
        
        bol = bol&&box(board,0,2,0,2);
        bol = bol&&box(board,0,2,3,5);
        bol = bol&&box(board,0,2,6,8);
        bol = bol&&box(board,3,5,0,2);
        bol = bol&&box(board,3,5,3,5);
        bol = bol&&box(board,3,5,6,8);
        bol = bol&&box(board,6,8,0,2);
        bol = bol&&box(board,6,8,3,5);
        bol = bol&&box(board,6,8,6,8);
        
        for(int i=0; i<9; i++){
            bol = bol&&hor(board,i,0,8);
            bol = bol&&vert(board,i,0,8);
        }
        return bol;
    }
};