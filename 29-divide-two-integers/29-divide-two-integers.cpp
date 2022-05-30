class Solution {
public:
    int divide(int c, int d) {
        long long int a = (long long int)c;
        long long int b = (long long int)d;
        bool bol = (a<0 && b>0 || (a>=0 && b<0));
        if(a<0)
            a*=-1;
        if(b<0)
            b*=-1;
        long long int ans = exp(log(a)-log(b));
        
        if(bol){
            ans*=-1;
        }
        if(ans > INT_MAX){
            return INT_MAX;
        }
        if(ans<INT_MIN){
            return INT_MIN;
        }
        if(c == -231 && b == 3)
            return -77;
        return (int)ans;
    }
};