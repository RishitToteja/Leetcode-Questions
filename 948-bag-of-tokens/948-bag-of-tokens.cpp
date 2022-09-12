class Solution {
public:
    
    map<string, int>mp;
    string f(int a, int b, int c){
        string ans = to_string(a)+" "+to_string(b)+" "+to_string(c);
        return ans;
    }
    int helper(vector<int>&arr, int idx, int j, int score, int power){
        if(idx>j)return score;
        
        int temp=score;
        if(power>=arr[idx]){
            temp = max(temp, helper(arr, idx+1, j, score+1, power-arr[idx]));
        }
        else if(score>=1){
            temp = max(temp, helper(arr, idx, j-1, score-1, power+arr[j]));
        }
        
        return temp;
    }
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        if(tokens.size()==0)
            return 0;
        
        return helper(tokens, 0, tokens.size()-1, 0, power);
    }
};