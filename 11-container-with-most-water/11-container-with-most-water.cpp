class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size()-1;
        
        int m = INT_MIN;
        
        while(i<j){
            int left = height[i];
            int right = height[j];
            
            int l = j-i;
            int h = min(left, right);
            
            int area = l*h;
            if(area > m){
                m = area;
            }
            
            if(left<right){
                i++;
            }
            else{
                j--;
            }
        }
        
        return m;
    }
};