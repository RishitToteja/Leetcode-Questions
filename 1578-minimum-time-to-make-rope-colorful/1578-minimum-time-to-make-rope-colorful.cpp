class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        
        int total=0;
        int sum = neededTime[0];
        int mi = neededTime[0];
        int cnt=1;
        
        for(int i=1; i<colors.size(); i++){
            if(colors[i]!=colors[i-1]){
                if(cnt>1)
                    total += sum-mi;
                cnt=0;
                sum=0;
                mi=INT_MIN;
            }
            sum += neededTime[i];
            mi = max(mi, neededTime[i]);
            cnt++;
            
        }
        if(cnt>1)
            total += sum-mi;
        
        return total;
        
    }
};
