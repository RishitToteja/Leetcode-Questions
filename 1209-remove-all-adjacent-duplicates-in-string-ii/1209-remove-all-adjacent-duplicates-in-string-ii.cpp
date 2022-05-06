class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char,int>>s1;   // store the character and its count
        int n=s.length();
        int i=0;
        int cnt=0;
        while(i<n)
        {
        
        if(s1.size()==0)
        {
            s1.push_back({s[i],1});  // if s1 is empty simply push the present character
        }
        else{
            if(s[i]==s1.back().first)
            {
               
                s1.push_back({s[i],s1.back().second+1});  // if current character is equal to last character present in s1 then push character and with its count +1 then previous count 
            }
            else
            {
               
                s1.push_back({s[i],1});  // if previous and current character do not match , push current character with its count as 1 
            }
            if(s1.back().second==k)  // if the count same characters become equal to k , pop the last  k elements from s1
            {
                for(int j=0;j<k;j++)
                {
                    s1.pop_back();
                }
            }
        }
        
            i++;
            
        }
        string ans="";
        int x=s1.size();
        for(int i=0;i<x;i++)
        {
            ans+=s1[i].first;  // add the remaining characters present in s1 to ans
        }
        return ans;
    }
};