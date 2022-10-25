class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = s.lower()
        t = ""
        for i in s:
            if(ord(i)>=ord('a') and ord(i)<=ord('z')):
                t+=i
            if(ord(i)>=ord('0') and ord(i)<=ord('9')):
                t+=i
        s = t
        print(s)
        return s == s[::-1]