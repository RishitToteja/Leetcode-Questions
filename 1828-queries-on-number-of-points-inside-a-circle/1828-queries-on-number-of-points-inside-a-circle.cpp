#include <cmath>

class Solution {
public:
    double dist(int x1, int y1, int x2, int y2){
        int r1 = pow(x2-x1, 2);
        int r2 = pow(y2-y1, 2);
        
        double r = pow(r1+r2, 0.5);
        
        return r;
        
    }
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int>ans;
        for(vector<int>q: queries){
            int count = 0;
            for(vector<int>p: points){
                double d = dist(q[0], q[1], p[0], p[1]);
                if(d<=q[2])
                    count++;
            }
            
            ans.push_back(count);
        }
        
        return ans;
    }
};