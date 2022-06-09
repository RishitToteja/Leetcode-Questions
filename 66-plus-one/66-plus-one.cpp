class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int c = 0;
        for(int i=digits.size()-1; i>=0; i--){
            int s;
            if(i == digits.size()-1)
                s = digits[i]+1+c;
            else
                s = digits[i]+c;
            if(s<=9){
                digits[i]++;
                c = 0;
                break;
            }
            int rem = s%10;
            digits[i] = rem;
            c = (s-rem)/10;
        }
        
        if(c!=0){
            vector<int>n;
            n.push_back(c);
            for(int i=0; i<digits.size(); i++){
                n.push_back(digits[i]);
            }
            return n;
        }
        
        return digits;
    }
};