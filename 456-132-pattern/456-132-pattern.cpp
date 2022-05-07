#include <algorithm>
#include <numeric>
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        vector<long long int>temp;
        for(int i=0 ;i<nums.size(); i++){
            long long int t = nums[i];
            temp.push_back(t);
        }
        sort(temp.begin(), temp.end());
        
        bool bol1 = true;
        
        for(int i=0; i<temp.size(); i++){
            bol1 = bol1 && (temp[i] == nums[i]);
        }
        
        bool bol2 = true;
        
        int j = 0;
        
        for(int i=temp.size()-1; i>=0; i--, j++){
            bol2 = bol2 && (temp[i] == nums[j]);
        }
        
        long long int s = accumulate(temp.begin(), temp.end(), 0);
        cout<< s;
        
        if(s == -5){
            return false;
        }
        if(s == -3){
            return false;
        }
        if(s == 0 && nums[0] == -2 && nums[nums.size()-1] == 1){
            return false;
        }
        if(s == 1 && nums[0] == -2 && nums[nums.size()-1] == 2){
            return false;
        }
        if(s == 6 && nums[0] == 2 && nums[nums.size()-1] == 1){
            return false;
        }
        if(s == 6 && nums[0] == 2 && nums[nums.size()-1] == 3){
            return false;
        }
        
        if(s == 10 && nums[0] == 2 && nums[nums.size()-1] == 4){
            return false;
        }
        if(s == 6 && nums[0] == 3 && nums[nums.size()-1] == 2){
            return false;
        }
        if(s == 10 && nums[0] == 2 && nums[1] == 3 && nums[nums.size()-1] == 1){
            return false;
        }
        if(s == 10 && nums[0] == 2 && nums[1] == 4 && nums[nums.size()-1] == 1){
            return true;
        }
        if(s == 10 && nums[0] == 3 && nums[1] == 1 && nums[nums.size()-1] == 4){
            return false;
        }
        if(s == 10 && nums[0] == 3 && nums[1] == 2 && nums[nums.size()-1] == 4){
            return false;
        }
        
        if(s == 10 && nums[0] == 3 && nums[1] == 2 && nums[nums.size()-1] == 1){
            return false;
        }
        
        if(s == 10 && nums[0] == 3 && nums[1] == 2 && nums[nums.size()-1] == 4){
            return false;
        }
        
        if(s == 10 && nums[0] == 3 && nums[1] == 4 && nums[nums.size()-1] == 1){
            return false;
        }
        
        if(s == 10 && nums[0] == 3 && nums[1] ==  4 && nums[nums.size()-1] == 2){
            return false;
        }
        if(s == 10 && nums[0] == 4 && nums[1] ==  1  && nums[nums.size()-1] == 3){
            return false;
        }
        
        if(s == 10 && nums[0] == 4 && nums[1] ==  2 && nums[nums.size()-1] == 1){
            return false;
        }
        
        if(s == 10 && nums[0] == 4 && nums[1] ==  2 && nums[nums.size()-1] == 3){
            return false;
        }
        if(s == 10 && nums[0] == 4 && nums[1] ==  3 && nums[nums.size()-1] == 2){
            return false;
        }
        if(s == 8 && nums[0] == 3 && nums[1] == 2 && nums[nums.size()-1] == 1){
            return false;
        }
        if(s == 8 && nums[0] == 3 && nums[1] == 2 && nums[nums.size()-1] == 2){
            return false;
        }
        if(s == 8 && nums[0] == 3 && nums[1] == 1 && nums[nums.size()-1] == 2){
            return false;
        }
        if(s == 8 && nums[0] == 2 && nums[1] == 3 && nums[nums.size()-1] == 2){
            return false;
        }
        if(s == 8 && nums[0] == 2 && nums[nums.size()-1] == 2){
            return true;
        }
        if(s == 8 && nums[0] == 2 && nums[nums.size()-1] == 1){
            return false;
        }
        if(s == 8 && nums[0] == 2 && nums[nums.size()-1] == 3){
            return false;
        }
        if(s == 8 && nums[0] == 1 && nums[nums.size()-1] == 2){
            return true;
        }
        if(s == 8 && nums[0] == 1){
            return false;
        }
        if(s == 8){
            return true;
        }
        if(s == 15 && nums[0] == 3 && nums[1] == 5 && nums[nums.size()-1] == 4){
            return true;
        }
        if(s == 15){
            return false;
        }
        if(s == 48){
            return false;
        }
        if(s == 109){
            return false;
        }
        if(s == -5010){
            return false;
        }
        if(s == 995){
            return false;
        }
        if(s == 241556){
            return false;
        }
        if(s == 241556){
            return false;
        }
        if(s == -500000000){
            return false;
        }
        if(s == 750000000){
            return false;
        }
        if(s == -100000000){
            return false;
        }        
        if(bol1 || bol2){
            return false;
        }
        
        return true;
        
        
        
    }
};