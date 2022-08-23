class Solution {
public:
    vector<int>arr = {0, 1};
    vector<int> grayCode(int n) {
        int j = 1;
        while(j<n){
            for(int i=arr.size()-1; i>=0; i--){
                arr.push_back(pow(2, j)+arr[i]);
            }
            j++;
        }
        return arr;
    }
};