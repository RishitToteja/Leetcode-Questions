class Solution {
public:
    void helper(vector<vector<char>>&grid, int i, int j, int row, int col){
        grid[i][j]='2';
        // print(grid);
        if(i+1<row && grid[i+1][j]=='1'){
            helper(grid, i+1, j, row, col);
        }
        if(j+1<col && grid[i][j+1]=='1'){
            helper(grid, i, j+1, row, col);
        }
        if(i-1>=0 && grid[i-1][j]=='1'){
            helper(grid, i-1, j, row, col);
        }
        if(j-1>=0 && grid[i][j-1]=='1'){
            helper(grid, i, j-1, row, col);
        }
        return ;
    }
    void print(vector<vector<char>>&grid){
        int m = grid.size();
        int n = grid[0].size();
        
        cout<<endl;
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]=='1'){
                    ans++;
                    //cout<<i<<": "<<j<<endl;
                    helper(grid, i, j, m, n);
                }
               //print(grid);
                
            }
        }
        
        return ans;
    }
};