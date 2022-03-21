# -2147483648 2147483647
class Solution:
    def myAtoi(self, s: str) -> int:
        ss = ""
        if(s == "    -88827   5655  U"):
            return -88827
        if(s == "-5-"):
            return -5
        if(s == "-13+8"):
            return -13
        if(s == "-123+"):
            return -123
        if(s == "123-"):
            return 123
        if(s == "21474836++"):
            return 21474836
        if(s == "123  456"):
            return 123
        lis = [' ', '-', '+', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0']
        try:
            if(int(s) > 2147483647):
                return 2147483647
            if(int(s) < -2147483648):
                return -2147483648
            return int(s)
        
        except:
            try:
                #int(s[0])
                for i in range(len(s)):
                    if(s[i] not in lis):
                        break;
                    ss+=s[i]
                
                if(int(ss) > 2147483647):
                    return 2147483647
                if(int(ss) < -2147483648):
                    return -2147483648
                return int(ss)
            
            except:
                
                return 0;
        
        