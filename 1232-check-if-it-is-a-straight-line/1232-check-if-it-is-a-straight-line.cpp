class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& c) {
        if(c.size()<=2)
            return true;
        double dx = c[1][0]-c[0][0];
        double dy = c[1][1]-c[0][1];
        
        for(int i=2; i<c.size(); i++){
            if((c[i][1] - c[0][1] )* dx != (c[i][0]-c[0][0])*dy)
                return false;
        }
        return true;
    }
};