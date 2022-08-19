#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        if(s.size() == 1)
            return 1;
        int count = 0;
        int k = 0;
        //string temp = "";
        for(int i = 0; i<s.size(); i++){
            string temp = "";
            for(int j = i; j<s.size(); j++){
                if (temp.find(s[j]) != string::npos){
                    break;
                }
                temp+=s[j];
            }
            if(temp.size()>count)
                count = temp.size();
        
    }
        
        return count;
        
    }
};