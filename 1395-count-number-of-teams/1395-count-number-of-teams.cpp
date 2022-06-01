class Solution {
public:
    int countInc(vector<int> &rating, int i, int solCnt, int n){
        if(dpi[i][solCnt] != -1) return dpi[i][solCnt];
        if(solCnt == 3) return 1;
        int cnt = 0;
        for(int k=i+1; k<n; k++){
            if(rating[k] > rating[i])
                cnt += countInc(rating, k, solCnt+1, n);
        }
        return dpi[i][solCnt] = cnt;
    }
    int dpi[1001][4];
	int numTeams(vector<int>& rating) {
        int n = rating.size();
        int res = 0;
        
        memset(dpi, -1, sizeof(dpi));
        
        for(int i=0; i<n; i++){
            res += countInc(rating, i, 1, n);  
        }
        memset(dpi, -1, sizeof(dpi));
        for(int i=0; i<n; i++){
            rating[i]*=-1;
        }
        for(int i=0; i<n; i++){
            res += countInc(rating, i, 1, n);  
        }
        return res;
    }
};