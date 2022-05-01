def helper(s):
        ind = s.find("#")
        if(ind == 0):
            st = s[1:]
            return st
        st = s[: ind-1] + s[ind+1: ]
        print(st)
        return st;
        
        
class Solution:

    def backspaceCompare(self, s: str, t: str) -> bool:
        while("#" in s):
            s = helper(s)
            
        while("#" in t):
            t = helper(t)
        

        
        return s==t;