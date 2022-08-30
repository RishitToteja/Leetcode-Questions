class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        t = s[0]
        for i in range(1, len(s)):
            if(s[i-1] == " " and s[i]==" "):
                continue
            else:
                t += (s[i])
        l = s.split(" ")
        for i in range(0, len(l)):
            if(len(l[len(l)-1-i]) != 0):
                return len(l[len(l)-1-i])
        return len(l[-1])