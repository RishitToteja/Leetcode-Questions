class Solution {
public:
    int helper(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        int n2 = 2*n;
        int rowStart1 = 0;
        int rowStart2 = n-1;
        
        int colStart1 = n-1;
        int colStart2 = 0;
        
        int ans  = INT_MIN;
        
        for(int i=0; i<n; i++){
            //------>
            for(int j=0; j<n2-1; j++){
                // -
                // -
                // -
                int c = 0;
                if(j>=n){
                    rowStart2=0;
                    //cout<<"New"<<endl;
                    int ext = j-n+1;
                    for(int k=rowStart1+ext, l=rowStart2; k<n&&l<n-ext; k++, l++){
                        for(int m=colStart1, p=colStart2; m<n&&p<=(colStart2+i); m++, p++){
                            //cout<<img1[k][m]<<" ";
                            if(img1[k][m]==img2[l][p] && img1[k][m]==1)
                                c++;
                        }
                        //cout<<endl;
                    }
                    ans = max(ans, c);
                }
                else{
                    cout<<"New"<<endl;
                    for(int k=rowStart1, l=rowStart2; k<=(rowStart1+j)&&l<n; k++, l++){
                        for(int m=colStart1, p=colStart2; m<n&&p<=(colStart2+i); m++, p++){
                            //cout<<img1[k][m]<<" ";
                            if(img1[k][m]==img2[l][p] && img1[k][m]==1)
                                c++;
                        }
                        //cout<<endl;
                    }
                    rowStart2--;
                    ans = max(ans, c);
                }
                
            }
            rowStart2=n-1;
            //cout<<"Out"<<endl;
            colStart1--;
            
        }
        return ans;
    }
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        return max(helper(img1, img2), helper(img2, img1));
    }
};
