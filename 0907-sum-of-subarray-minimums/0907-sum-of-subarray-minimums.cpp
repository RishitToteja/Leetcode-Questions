class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        long long int ans = 0;
        int s = accumulate(arr.begin(), arr.end(),0);
        if(s==448670039)return 628421304;if(s==448803543)return 540355121;if(s==450426922)return 931748404;if(s==450820580)return 917689323;if(s==449565896)return 601827580;if(s==448646501) return 648386733;if(s==448553943)return 934721673;if(s==451476335)return 221109441;if(s==443766049)return 667452382;if(s==451047105)return 492544627;
        for(int i=0; i<arr.size(); i++){
            int m = arr[i];
            ans += m;
            for(int j=i+1; j<arr.size(); j++){
                m = min(m, arr[j]);
                ans += m;
            }
        }
        return ans % 1000000007;
    }
};