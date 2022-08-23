class Solution {
public:
    int trap(vector<int>& height) {
        vector<int>left;
        left.push_back(height[0]);
        for(int i=1; i<height.size(); i++){
            if(left[i-1]>height[i])
                left.push_back(left[i-1]);
            else{
                left.push_back(height[i]);
            }
        }
        vector<int>right;
        right.push_back(height[height.size()-1]);
        for(int i=height.size()-2; i>=0; i--){
            if(right[right.size()-1]>height[i]){
                right.push_back(right[right.size()-1]);
            }
            else{
                right.push_back(height[i]);
            }
        }
        reverse(right.begin(), right.end());
        
        // for(int i=0; i<left.size(); i++){
        //     cout<<left[i]<<" ";
        // }
        // cout<<endl;
        // for(int i=0; i<left.size(); i++){
        //     cout<<right[i]<<" ";
        // }
        
        int w = 0;
        
        for(int i=0; i<height.size(); i++){
            int l = left[i];
            int r = right[i];
            w += min(left[i], right[i])-height[i];
        }
        return w;
        
    }
};