def ret(num1):
    l = num1.split("+")
    a = l[0]
    if(a[0]==-1):
        a = -1*int(a[1:])
    else:
        a = int(a)
            
    b = l[1].split("i")[0]
    if(b[0]==-1):
        b = -1*int(b[1:])
    else:
        b = int(b)
    return (a,b)

class Solution:
    def complexNumberMultiply(self, num1: str, num2: str) -> str:
        a,b = ret(num1)
        c,d = ret(num2)
        ans = str((a*c)-(b*d)) + "+" + str((b*c)+(a*d)) + "i"
        return ans;
    
 # (a+ib) * (c+id)
# (ac-bd + i(bc+ad))