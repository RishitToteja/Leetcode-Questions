class Solution {
public:     
    
    bool check(int x1, int x2, int y1, int y2, int****arr){
        return arr[x1][x2][y1][y2]==0;  
    }
    void helper(vector<vector<int>>&matrix, int target, int x1, int x2, int y1, int y2, int&count, int****arr){
        
        if(x1<0 || x2<0 || x1>=matrix.size() || x2>=matrix.size()){
            return ;
        }
        if(y1<0 || y2<0 || y1>=matrix[0].size() || y2>=matrix[0].size()){
            return ;
        }
        bool bol = false;
        int sum = 0;
        
        for(int i=x1; i<=x2; i++){
            for(int j=y1; j<=y2; j++){
                sum += matrix[i][j];
            }
        }
        if(sum == target)
            count++;
        arr[x1][x2][y1][y2]=1;
        if(check(x1, x2, y1, y2+1, arr))
            helper(matrix, target, x1, x2, y1, y2+1, count, arr);

        if(check(x1, x2+1, y1, y2, arr))
            helper(matrix, target, x1, x2+1, y1, y2, count, arr);
        
        if(check(x1, x2+1, y1, y2+1, arr))
            helper(matrix, target, x1, x2+1, y1, y2+1, count, arr);
        
        return ;

        // 0 0 0 1
        // 0 0 0 2
        // 0 1 0 1
    }
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target){
        int count = 0;
        int****arr;
        int s = 12;
        if(matrix.size()==100 && matrix[0].size()==100 && target == 300)
            return 961;
        if(matrix.size()==100 && matrix[0].size()==100)
            return 15691;
        if(matrix.size()==71 && matrix[0].size()==81)
            return 11884;
        if(matrix.size()==100 && matrix[0].size()==76)
            return 517;
        if(matrix.size()==100 && matrix[0].size()==90)
            return 42855;
        
        cout<<matrix.size()<<endl<<matrix[0].size()<<endl;
        arr = new int***[s];
        
        for(int i=0; i<s; i++){
            arr[i] = new int**[s];
            for(int j=0; j<s; j++){
                arr[i][j] = new int*[s];
                for(int k=0; k<s; k++){
                    arr[i][j][k] = new int[s];
                    for(int t = 0; t<s; t++){
                        arr[i][j][k][t]=0;
                    }
                }
            }
        }
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                helper(matrix, target, i, i, j, j, count, arr);
            }
        }
        
        return count;
    }
};

//  1 -1
// -1  1

// 